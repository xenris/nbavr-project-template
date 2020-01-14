# nblib project template

## About

This is a template for creating projects for 8-bit AVR microcontrollers using the [nblib](https://github.com/xenris/nblib) library.

## Requirements

* Git
* Bash
* Tup
* Avr-gcc
* Avr-binutils
* Avr-libc
* Avrdude
* Picocom
* Text editor

## Use

1. Clone this repository with "git clone https://github.com/xenris/nblib-project-template.git project-name".
1. Delete the .git/ directory.
1. Look in build.config for configuration options.
1. Run "./build.sh" to initialise the project and see options including building and uploading.
1. Explore the source code.
1. Explore the documentation of [nblib](https://github.com/xenris/nblib/blob/master/docs/index.hpp.md).
1. Explore this example project: [8x8 LED Matrix Display](https://github.com/xenris/led-matrix-display)
1. Replace the contents of this readme with your own.

## License

Only build.sh has a license, the MIT license. All other files in this project
are merely templates. They belong to me (Henry Shepperd) while they are a part
of nblib-project-template, and belong to you as soon as you modify or add to
them as part of your own project.
