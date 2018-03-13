#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK();
INCLUDE_TIMER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    const uint32_t CpuFreq = 16000000;

    using SystemTimer = nbos::hw::Timer1;
    using SerialUsart = nbos::hw::Usart0;
    using cout_t = nbos::Queue<char, 40>;
    using LedPin = nbos::hw::PortB::Pin5;

    using Clock = nbos::Clock<SystemTimer, CpuFreq>;

    static cout_t cout;

    nbos::Serial<SerialUsart, cout_t>::init(CpuFreq, 115200, &cout);

    static Hello<Clock, cout_t> hello(cout);
    static Flash<Clock, LedPin> flash;

    static nbos::Task<Clock>* tasks[] = {&hello, &flash};

    nbos::TaskManager<Clock> tm(tasks);
}
