# nbos project template

## About

This is a template for creating projects for 8-bit AVR microcontrollers using the [nbos](https://github.com/xenris/nbos) library.

## Requirements

* Git
* Bash
* Tup
* Avr-gcc
* Avr-binutils
* Avr-libc
* Avrdude
* Text editor

For Windows users, Git and Bash are available at [git-scm.com](https://git-scm.com). (Install with default options.)

To simplify things I've built Tup and all the AVR tools (latest versions as of 14-Aug-2017) into a single package available for [Windows](https://drive.google.com/open?id=0BwzYmFJSZljhYTNBVzdGTUpFMDA) and [Linux](https://drive.google.com/open?id=0BwzYmFJSZljhazZpVGpjeE5mOTA). Alternatively, for Linux, these are probably all available via the package manager.

## Use

1. Clone this repository with "git clone https://github.com/xenris/nbos-project-template.git project-name".
1. If you downloaded avr-tools, unzip it to a convenient location.
1. Look in build.config for configuration options.
1. Run "./build.sh" to see options, including building and uploading. (nbos will be downloaded on first run.)
1. Delete .git directory.
1. Replace the contents of this readme with your own.
1. Explore the source code.
1. Explore the documentation of [nbos](https://github.com/xenris/nbos/blob/master/docs/index.hpp.md).
1. Explore this example project: [8x8 LED Matrix Display](https://github.com/xenris/led-matrix-display)

## License

Only build.sh has a license, the MIT license. All other files in this project
are merely templates. They belong to me (Henry Shepperd) while they are a part
of nbos-project-template, and belong to you as soon as you modify or add to
them as part of your own project.
