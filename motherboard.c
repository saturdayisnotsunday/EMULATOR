#include "CPU/cpu.h"
#include <stdio.h>






int main(void)
{
    struct cpuState state = cpu_run(0, 1);
    printf("now next is I %i SB %i\n",state.init_state, state.sb_init_state);

    return 0;
}