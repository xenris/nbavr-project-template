#include "main.hpp"

void main() {
    const Integer CpuFreq = 16000000;

    using SystemTimer = nbos::hw::Timer1;
    using SerialUsart = nbos::hw::Usart0;
    using LedPin = nbos::hw::PortB::Pin5;

    using Clock = nbos::Clock<SystemTimer, CpuFreq>;

    static nbos::Queue<Char, 40> cout;

    nbos::Serial<SerialUsart>::init(CpuFreq, 115200, &cout);

    static Hello<Clock> hello(cout);
    static Flash<Clock, LedPin> flash;

    static nbos::Task<Clock>* tasks[] = {&hello, &flash};

    nbos::TaskManager<Clock> tm(tasks);
}
