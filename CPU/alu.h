#ifndef ALU_H
#define ALU_H

struct addition { 
    unsigned int sum; 
    int overflow_add;
}; 
struct subtraction{
   unsigned int result;
   int underflow;
};

struct addition addnum(unsigned int a, unsigned int b); 
struct subtraction subnum(unsigned int a, unsigned int b); 
#endif
