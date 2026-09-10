#include "alu.h"






struct addition addnum(unsigned int a, unsigned int b) {
    struct addition s;
    s.sum = a + b;
    if (s.sum < a) {
        s.overflow_add = 1; //  occurred
    } else {
        s.overflow_add = 0; // Safe addition
    }
    return s;
}
struct subtraction subnum(unsigned int a, unsigned int b){
   struct subtraction sb;
   sb.result = a - b;

    // NOTE: i need to know about undeflow using google
    if (b > a) {
        sb.underflow = 1; // Underflow/Borrow occurred  
    } else {
        sb.underflow = 0; // Safe subtraction
    }
    
    return sb;
}

struct division divnum(unsigned int a, unsigned int b) {
    struct division dv;
    
    if (b == 0) {
        dv.divres = 0;       
        dv.overflow_div = 1; 
        return dv;
    }

    dv.divres = a / b;
    dv.overflow_div = 0; 
    return dv;
}

// i took help using internet for multiplication as it used a new thing named limit.h
#include <limits.h> 

struct multiplication mulnum(unsigned int a, unsigned int b) {
    struct multiplication ml;
    ml.mulres = a * b;

    // If a is 0, multiplication can never overflow
    if (a != 0 && b > UINT_MAX / a) {
        ml.overflow_mul = 1;
    } else {
        ml.overflow_mul = 0;
    }

    return ml;
}


