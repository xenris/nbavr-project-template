#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbos.hpp>

template <class Clock>
struct Hello : nbos::Task<Clock> {
    nbos::Queue<char>& cout;
    int16_t count;

    Hello(nbos::Queue<char>& cout) : cout(cout) {
    }

    void loop() override {
        cout << "hello! (" << count << ")\n";

        count++;

        this->sleep(Clock::millisToTicks(1000));
    }
};

#endif
