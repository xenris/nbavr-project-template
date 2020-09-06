#include "main.hpp"

constexpr uint64_t cpuFreq = 16000000;
constexpr uint64_t serialBaud = 115200;

using Tc = nblib::hw::Tc1;
using Usart = nblib::hw::Usart0;
using Sleep = nblib::hw::Sleep;
using LedPin = nblib::hw::PortB::Pin5;

static void flushUsart(void*);

static nblib::Queue<char, 32> cout;

static bool _wake = false;

void main() {
    Tc::waveform(Tc::Waveform::ctcOcra);
    Tc::compareAIntEnable(true);
    Tc::compareA(cpuFreq / 256);
    Tc::clock(Tc::Clock::div256);

    LedPin::direction(LedPin::Direction::output);

    cout.setCallback(flushUsart, (void*)nullptr);

    Usart::baud(cpuFreq / (8 * serialBaud) - 1);
    Usart::baudMode(Usart::BaudMode::doubleSpeed);
    Usart::transmitterEnable(true);

    Sleep::mode(Sleep::Mode::idle);
    Sleep::enable(true);

    nblib::interruptsEnable(true);

    int count = 0;

    while(true) {
        while(!atomic(_wake)) {
            Sleep::sleep();
        }

        atomic(_wake) = false;

        cout << "Hello (" << count << ")\n";

        ++count;

        LedPin::outputToggle();
    }
}

static void flushUsart(void*) {
    Usart::dataRegisterEmptyIntEnable(true);
}

vectorTc1CompareA {
    _wake = true;
}

vectorUsart0DataRegEmpty {
    if(Optional<char> d = cout.pop()) {
        Usart::tx(uint8_t(*d));
    } else {
        Usart::dataRegisterEmptyIntEnable(false);
    }
}
