#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class Nbavr, class ledPin>
struct Flash : Task {
    Flash() {
        ledPin::direction(Direction::Output);
    }

    void loop() override {
        ledPin::toggle();

        sleep(Nbavr::getTicks() + Nbavr::millisToTicks(500));
    }
};

#endif
