#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK();
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    const uint32_t CpuFreq = 16000000;

    typedef PinB5 ledPin;
    typedef TimerCounter1 systemTimer;
    typedef Usart0 serialUsart;

    typedef Clock<systemTimer, CpuFreq> Clock;

    Clock::init();

    StreamBuffer<char, 40> cout;

    Serial<serialUsart>::init(CpuFreq, 9600, &cout);

    Hello<Clock> hello(cout);
    Flash<Clock, ledPin> flash;

    Task<Clock>* tasks[] = {&hello, &flash};

    TaskManager<Clock> tm(tasks);
}
