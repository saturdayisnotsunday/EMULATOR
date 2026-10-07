#ifndef CPU_H
#define CPU_H
struct cpuState{
    int init_state;
    int sb_init_state;
};
struct cpuState cpu_run(int initype, int subinitype);
#endif