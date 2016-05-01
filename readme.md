# [nbavr](https://github.com/xenris/nbavr) project template

This is a template for creating 8-bit Atmel AVR projects using the [nbavr](https://github.com/xenris/nbavr) library.

## About

[nbavr](https://github.com/xenris/nbavr) is a c library for 8-bit Atmel AVR microprocessors (such as those found on Arduinos).

This template is designed for Linux. Anyone using other OSs will have to work out some things themselves.

## Requirements

* avr-gcc
* avr-binutils
* avr-libc
* avrdude
* tup
* git

## Use

1. Clone this repository with "git clone https://github.com/xenris/nbavr-project-template.git projectname" (where "projectname" is the name of your project).
1. Delete the .git directory.
1. Look in build.config, tup.config, and config.h for configuration options.
1. Run build.sh to compile the project (first run will also download nbavr). Add the -u option to also upload to a device.
1. Replace the contents of this readme with your own readme.
1. Explore the documentation of [nbavr](https://github.com/xenris/nbavr).

To update nbavr you can either delete the nbavr directory under lib/ and run build.sh, or cd into lib/nbavr/ and run "git pull".
