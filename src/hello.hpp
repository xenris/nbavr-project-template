#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

template <class Clock>
struct Hello : Task<Clock> {
    Stream<char>& cout;
    uint16_t count = 0;

    Hello(Stream<char>& cout) : cout(cout) {
    }

    void loop() override {
        cout << "hello! (" << count << ')' << endl;

        count++;

        this->sleep(Clock::millisToTicks(1000));
    }
};

#endif
