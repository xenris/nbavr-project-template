#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

template <class Clock, class cout_t>
struct Hello : nbavr::Task<Clock> {
    cout_t& cout;
    uint16_t count = 0;

    Hello(cout_t& cout) : cout(cout) {
    }

    void loop() override {
        cout << "hello! (" << count << ")\n";

        count++;

        this->sleep(Clock::millisToTicks(1000));
    }
};

#endif
