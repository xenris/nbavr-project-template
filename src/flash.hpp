#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class Clock, class LedPin>
struct Flash : nbavr::Task<Clock> {
    Flash() {
        LedPin::direction(nbavr::Direction::Output);
    }

    void loop() override {
        LedPin::toggle();

        this->sleep(Clock::millisToTicks(500));
    }
};

#endif
