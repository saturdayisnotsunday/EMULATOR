#include <stdio.h>


char RAM[4096];
//read
int ram_r(int addr){
    return RAM[addr];
    
}
// write
int ram_w(int addr, char val){
    RAM[addr] = val;
    return 0;
}

int main(){
    ram_w(10, 25);
    printf("%d\n", ram_r(10));
    return 0;
}