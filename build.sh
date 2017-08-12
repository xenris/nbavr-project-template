#!/bin/sh

set -e

source ./build.config

if [ ! -d "lib/nbavr/" ]; then
    git clone https://github.com/xenris/nbavr.git lib/nbavr/
fi

tup

avr-size gen/firmware.elf -C --mcu=$mcu

elf="gen/firmware.elf"

if [ "${1}" = "-u" ]; then
    avrdude -p $mcu -P $port -c $programmer -e -U flash:w:$elf
elif [ "${1}" == "-t" ]; then
    echo "---------------------------------"
    echo "Exit with ctrl+c"
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
fi
