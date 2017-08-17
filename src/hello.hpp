#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

template <class Clock>
struct Hello : Task<Clock> {
    Stream<char>& stdout;
    uint16_t count = 0;

    Hello(Stream<char>& stdout) : stdout(stdout) {
    }

    void loop() override {
        stdout << "hello! (" << count << ')' << endl;

        count++;

        this->sleep(Clock::millisToTicks(1000));
    }
};

#endif
