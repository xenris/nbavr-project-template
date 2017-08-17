#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class Clock, class ledPin>
struct Flash : Task<Clock> {
    Flash() {
        ledPin::direction(Direction::Output);
    }

    void loop() override {
        ledPin::toggle();

        this->sleep(Clock::millisToTicks(500));
    }
};

#endif
