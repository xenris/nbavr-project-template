#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

template <class Nbavr>
struct Hello : Task {
    Stream<char>& stdout;
    uint16_t count = 0;

    Hello(Stream<char>& stdout) : stdout(stdout) {
    }

    void loop() override {
        stdout << "hello! (" << count << ')' << endl;

        count++;

        sleep(Nbavr::getTicks() + Nbavr::millisToTicks(1000));
    }
};

#endif
