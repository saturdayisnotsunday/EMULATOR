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
