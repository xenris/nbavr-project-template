#!/bin/sh

# Copyright (c) 2017 Henry Shepperd

# MIT License (https://opensource.org/licenses/MIT)

set -e

source ./build.config

if [[ "$mcu" =~ ^at.* ]]; then
    arch="avr"
    mmcu=$mcu
elif [[ "$mcu" =~ ^stm32f1.* ]]; then
    arch="arm"
    mmcu="cortex-m3"
fi

if [ $avr_tools ]; then
    if [ -d $avr_tools ]; then
        PATH=$avr_tools/bin:$PATH
        avrdudeconfig="-C $avr_tools/etc/avrdude.conf"
    else
        echo "$avr_tools not found"
        exit 1
    fi
fi

if [ ! -d ".tup" ]; then
    tup init
fi

# Make sure nbos is initialised.
if [[ $(git submodule status lib/nbos) =~ ^-.* ]]; then
    git submodule init lib/nbos
    git submodule update lib/nbos
fi

elf="gen/firmware.elf"
bin="gen/firmware.bin"

# Iterate through args.
args=$*
for ((i = 0; i < ${#args}; i++)); do
    arg="${args:$i:1}"

    case "$arg" in
    'b')
        echo "---------------------------------"
        echo "Building"
        echo "---------------------------------"

        PATHS=$(find src/ -name '*.c' -o -name '*.cpp' -o -name '*.S')

        rm -f Tupresources

        echo "arch = $arch" >> Tupresources
        echo "mmcu = $mmcu" >> Tupresources
        echo "CFLAGS += -D__${mcu}__" >> Tupresources

        for p in $PATHS; do
            echo "SRC_FILES += $p" >> Tupresources
        done

        tup

        ;;
    'm')
        echo "---------------------------------"

        case $arch in
        "avr")
            avr-size $elf -C --mcu=$mmcu

            ;;
        "arm")
            arm-none-eabi-size $elf

            ;;
        esac

        ;;
    'u')
        echo "---------------------------------"
        echo "Uploading"
        echo "---------------------------------"

        case $arch in
        "avr")
            if [ -a $upload_port ]; then
                avrdude -b $upload_baud $avrdudeconfig -p $mmcu -P $upload_port -c $programmer -e -U flash:w:$elf:e
            else
                echo "$upload_port does not exist"
            fi

            ;;
        "arm")
            st-flash --reset write $bin 0x08000000

            ;;
        esac

        ;;
    's')
        echo "---------------------------------"
        echo "Serial - Exit with ctrl+c"
        echo "---------------------------------"

        if [ -a $serial_port ]; then
            set +e
            trap ' ' INT

            stty -F $serial_port $serial_baud -cstopb -parenb cs8 -echo -icanon raw
            stty -echo -icanon

            exec 3<> $serial_port
            cat <&3 &
            P1=$!
            cat >&3

            kill $P1
            wait $P1 2>/dev/null

            stty echo icanon

            echo ''

            set -e
        else
            echo "$serial_port does not exist"
        fi

        ;;
    'n')
        echo "---------------------------------"
        echo "Updating nbos"
        echo "---------------------------------"

        git submodule update --remote lib/nbos

        ;;
    ' ')
        ;;
    *)
        echo "$arg is not an option"
    esac
done

if [ "$#" == "0" ]; then
    echo "b -> Build"
    echo "m -> Show memory usage"
    echo "u -> Upload"
    echo "s -> Serial communication"
    echo "n -> Update nbos"
    echo ""
    echo "e.g. ./build.sh bmus"
fi
