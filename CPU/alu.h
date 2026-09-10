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
struct division{
    unsigned int divres;
    int overflow_div;
};
struct multiplication{
 unsigned int mulres;
 int overflow_mul;
};

struct addition addnum(unsigned int a, unsigned int b); 
struct subtraction subnum(unsigned int a, unsigned int b); 
struct division divnum(unsigned int a, unsigned int b);
struct multiplication mulnum(unsigned int a, unsigned int b);

#endif
