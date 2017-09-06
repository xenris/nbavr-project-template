#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK();
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    const uint32_t CpuFreq = 16000000;

    using ledPin = PinB5;
    using systemTimer = TimerCounter1;
    using serialUsart = Usart0;
    using cout_t = Queue<char, 40>;

    using Clock = Clock<systemTimer, CpuFreq>;

    cout_t cout;

    Serial<serialUsart, cout_t>::init(CpuFreq, 115200, &cout);

    Hello<Clock, cout_t> hello(cout);
    Flash<Clock, ledPin> flash;

    Task<Clock>* tasks[] = {&hello, &flash};

    TaskManager<Clock> tm(tasks);
}
