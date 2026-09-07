#include <stdio.h>
#include "alu.h"
#include <stdbool.h>

struct _register { 
    int R[8];  
    bool oR[8];    
    int Rfull; 
};



int main() {
    unsigned int a = 1;
    unsigned int b = 3; 
    
    
    struct addition r = addnum(a, b); 
    struct _register Reg = {
    .oR = {false, false, false, false, false, false, false, false},
    .Rfull = 0
};
    
    
    printf("Result of %u + %u = %u\n", a, b, r.sum);
    printf("Overflow status: %d\n", r.overflow_add);
    // Reg.R[0] = r.sum;
    
    for (int i = 0, j = 7; i < j; i++) {
    if(Reg.oR[i]==false){
        Reg.R[i] = r.sum;
        printf("saved at Reg.R[%i]",i);
        break;
    }
    }



    
    return 0;
}

