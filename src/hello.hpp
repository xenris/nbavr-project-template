#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbos.hpp>

template <class Clock>
struct Hello : nbos::Task<Clock> {
    nbos::Atomic<nbos::Queue<char>>& cout;
    uint16_t count = 0;

    Hello(nbos::Atomic<nbos::Queue<char>>& cout) : cout(cout) {
    }

    void loop() override {
        cout << "hello! (" << count << ")\n";

        count++;

        this->sleep(Clock::millisToTicks(1000));
    }
};

#endif
