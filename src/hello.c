#include "hello.h"

static void setup(void);
static void loop(void);

Task helloTask = {
    .setup = setup,
    .loop = loop,
};

static struct {
    uint16_t count;
} state;

static void setup(void) {
    state.count = 0;
}

static void loop(void) {
    printstr(stdout, "hello! (");
    printi16(stdout, state.count, PrintUDec);
    printstr(stdout, ")\n");

    state.count++;

    delay(&helloTask, MS_TO_TICKS(1000));
}
