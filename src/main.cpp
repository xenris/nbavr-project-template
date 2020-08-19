#include "main.hpp"

constexpr uint64_t cpuFreq = 16000000;
constexpr uint64_t serialBaud = 115200;

using Timer = nblib::hw::Timer1;
using Usart = nblib::hw::Usart0;
using Sleep = nblib::hw::Sleep;
using LedPin = nblib::hw::PortB::Pin5;
using Pin = nblib::hw::Pin;

static void flushUsart(void*);

static nblib::Queue<char, 32> cout;

static bool _wake = false;

void main() {
    Timer::waveform(Timer::Waveform::ctcOcra);
    Timer::compareAIntEnable(true);
    Timer::compareA(cpuFreq / 256);
    Timer::clock(Timer::Clock::div256);

    LedPin::direction(Pin::Direction::output);

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

vectorTimer1CompareA {
    _wake = true;
}

vectorUsart0DataRegEmpty {
    if(Optional<char> d = cout.pop()) {
        Usart::tx(uint8_t(*d));
    } else {
        Usart::dataRegisterEmptyIntEnable(false);
    }
}
