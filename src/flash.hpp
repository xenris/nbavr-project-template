#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class Nbavr, class ledPin>
struct Flash : Task<Nbavr> {
    Flash() {
        ledPin::direction(Direction::Output);
    }

    void loop() override {
        ledPin::toggle();

        this->sleep(Nbavr::millisToTicks(500));
    }
};

#endif
