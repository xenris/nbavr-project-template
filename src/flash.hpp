#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbos.hpp>

template <class Clock, class LedPin>
struct Flash : nbos::Task<Clock> {
    Flash() {
        LedPin::mode(LedPin::Mode::output);
    }

    void loop() override {
        LedPin::toggle();

        this->sleep(Clock::millisToTicks(500));
    }
};

#endif
