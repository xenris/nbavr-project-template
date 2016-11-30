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
    print(stdout, "hello! (", state.count, ")\n");

    state.count++;

    delay(&helloTask, MS_TO_TICKS(1000));
}
