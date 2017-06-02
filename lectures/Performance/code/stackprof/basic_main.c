#include "stackprof.h"
#include "register.h"
#include "printf.h"
#include "timer.h"

void main(void) {
    // Every 1 s. 4000-sample limit.
    stackprof_init(1000000, 4000);

    system_enable_interrupts();

    stackprof_on();

    for (int i = 0; i < 10; i++) {
        if (i % 3 == 0) {
            for (volatile int j = 0; j < 10000000; j++) {}
        } else {
            delay(1);
        }

        // A little janky. Keep this from being part of profile.
        printf("# i = %d\n", i);
    }

    stackprof_off();

    stackprof_dump();
}
