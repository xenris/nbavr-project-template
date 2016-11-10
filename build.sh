#!/bin/sh

set -e

source ./build.config

if [ ! -d "lib/nbavr/" ]; then
    git clone https://github.com/xenris/nbavr.git lib/nbavr/
fi

tup

avr-size gen/firmware.elf -C --mcu=$mcu

if [ "${1}" = "-u" ]; then
    pkill picocom && sleep 1 || true

    avrdude -p $mcu -P $port -c $programmer -e -U flash:w:gen/firmware.elf
fi
