#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK();
INCLUDE_TIMER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    const uint32_t CpuFreq = 16000000;

    using SystemTimer = nbavr::hw::Timer1;
    using SerialUsart = nbavr::hw::Usart0;
    using cout_t = nbavr::Queue<char, 40>;
    using LedPin = nbavr::hw::PortB::Pin5;

    using Clock = nbavr::Clock<SystemTimer, CpuFreq>;

    using TT = Clock::Timer;

    static cout_t cout;

    nbavr::Serial<SerialUsart, cout_t>::init(CpuFreq, 115200, &cout);

    static Hello<Clock, cout_t> hello(cout);
    static Flash<Clock, LedPin> flash;

    static nbavr::Task<Clock>* tasks[] = {&hello, &flash};

    nbavr::TaskManager<Clock> tm(tasks);
}
