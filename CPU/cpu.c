#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "alu.h"

struct CPU {
    // registers
    int R[8];
    bool oR[8];
    int Rfull;
    // rest _ _ _
};

struct CPU c = {
    .oR = {false, false, false, false, false, false, false, false},
    .Rfull = 0,
};

int ArithematicUnit(const char *type, unsigned int a, unsigned int b)
{
    if (strcmp("add", type) == 0) {
        struct addition r = addnum(a, b);

        for (int i = 0; i < 8; i++) {
            if (c.oR[i] == false) {
                c.R[i] = r.sum;
                c.oR[i] = true;
                break;
            }
        }
    } else if (strcmp("sub", type) == 0) {
        struct subtraction r = subnum(a, b);

        for (int i = 0; i < 8; i++) {
            if (c.oR[i] == false) {
                c.R[i] = r.result;
                c.oR[i] = true;
                break;
            }
        }
    } else {
        printf("[DEBUG, cpu.c] unknown arithmetic input \"%s\" ", type);
    }

    return 0;
}

int cpu_run()
{
    return 0;
}
