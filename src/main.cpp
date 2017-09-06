#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK();
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    const uint32_t CpuFreq = 16000000;

    using LedPin = PinB5;
    using SystemTimer = TimerCounter1;
    using SerialUsart = Usart0;
    using cout_t = Queue<char, 40>;

    using Clock = Clock<SystemTimer, CpuFreq>;

    cout_t cout;

    Serial<SerialUsart, cout_t>::init(CpuFreq, 115200, &cout);

    Hello<Clock, cout_t> hello(cout);
    Flash<Clock, LedPin> flash;

    Task<Clock>* tasks[] = {&hello, &flash};

    TaskManager<Clock> tm(tasks);
}
