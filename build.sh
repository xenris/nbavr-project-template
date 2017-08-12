#!/bin/sh

set -e

source ./build.config

# Clone nbavr if it doesn't exist.
if [ ! -d "lib/nbavr/" ]; then
    git clone https://github.com/xenris/nbavr.git lib/nbavr/
fi

elf="gen/firmware.elf"

# Iterate through args.
args=$*
for ((i = 0; i < ${#args}; i++)); do
    arg="${args:$i:1}"

    case "$arg" in
    'b')
        echo "---------------------------------"
        echo "Building"
        echo "---------------------------------"

        tup

        ;;
    'm')
        echo "---------------------------------"

        avr-size $elf -C --mcu=$mcu

        ;;
    'u')
        echo "---------------------------------"
        echo "Uploading"
        echo "---------------------------------"

        avrdude -p $mcu -P $upload_port -c $programmer -e -U flash:w:$elf

        ;;
    's')
        echo "---------------------------------"
        echo "Serial - Exit with ctrl+c"
        echo "---------------------------------"

        set +e
        trap ' ' INT

        stty -F $serial_port 9600 -cstopb -parenb cs8 -echo -icanon raw
        stty -echo -icanon

        cat < /dev/ttyUSB0 &
        P1=$!
        cat > /dev/ttyUSB0

        kill $P1
        wait $P1 2>/dev/null

        stty echo icanon

        echo ''

        set -e

        ;;
    'n')
        echo "---------------------------------"
        echo "Updating nbavr"
        echo "---------------------------------"

        cd lib/nbavr/
        git pull
        cd ../../

        ;;
    ' ')
        ;;
    *)
        echo "$arg is not an option"
    esac
done

if [ "$#" -eq "0" ]
then
    echo "b -> Build"
    echo "m -> Show memory usage"
    echo "u -> Upload"
    echo "s -> Serial communication"
    echo "n -> Update nbavr"
    echo ""
    echo "e.g. ./build.sh bmus"
fi
