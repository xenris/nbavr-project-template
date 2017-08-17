# [nbavr](https://github.com/xenris/nbavr) project template

This is a template for creating 8-bit Atmel AVR projects using the [nbavr](https://github.com/xenris/nbavr) library.

## About

[nbavr](https://github.com/xenris/nbavr) is a c++ library for 8-bit Atmel AVR microprocessors (such as those found on Arduinos).

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

1. Clone this repository with "git clone https://github.com/xenris/nbavr-project-template.git project-name".
1. Create the master branch for your project with "git checkout -b master".
1. If you downloaded avr-tools, unzip it to a convenient location.
1. Look in build.config for configuration options.
1. Run "./build.sh" to see options, including building and uploading. (nbavr will be downloaded on first run.)
1. Replace the contents of this readme with your own.
1. Explore the source code.
1. Explore the documentation of [nbavr](https://github.com/xenris/nbavr/blob/master/docs/index.md).
1. Explore this example project: [8x8 LED Matrix Display](https://github.com/xenris/led-matrix-display)

### Updating nbavr

1. "./build.sh n"

### Updating nbavr-project-template

1. "git fetch"
1. "git merge nbavr-project-template"
1. If any conflicts occur:
    1. "git status" to see where they are.
    1. Go through the conflicts, applying your own changes to the updates.
    1. "git add \[file\]"
    1. "git commit"
