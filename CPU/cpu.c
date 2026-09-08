#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alu.h"

struct CPU {
    // registers
    int R[8];
    bool oR[8];
    int Rfull;
    char instructions[40];
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

/*
so we have to create initialisation types that is doing the specific type of tasks ona specifc type of initalization
####
0 -> just initialised{
  * go to rom and fetch initial instructions
  * store them one by one and execute
}
*/


// int interpreter(){
//     return 0;
// }

int cpu_run(int initype)
{
    if(initype == 0){
        printf("[DEBUG, cpu.c] initialization type 0\n");
        // i will be using documentations for getting read file program in C
        // source: https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c
        char * buffer = 0;
        long length;
        FILE * f = fopen ("rom.txt", "r"); // Changed to "r" if it's text; keep "rb" if it's a raw binary

        if (f)
        {
            fseek (f, 0, SEEK_END);
            length = ftell (f);
            fseek (f, 0, SEEK_SET);
    
    
            buffer = malloc (length + 1); 
    
            if (buffer)
            {   
        
                size_t bytesRead = fread (buffer, 1, length, f);
                buffer[bytesRead] = '\0'; 
    }
            else 
    {
        
                fprintf(stderr, "Error: Memory allocation failed.\n");
            }
            fclose (f);
            printf("content: %s\n", buffer);
            buffer = c.instructions;
        }
        else 
        {
          fprintf(stderr, "Error: Could not open file.\n");
        }
        // now main work satrts from here 

        if (buffer){
            char *line = strtok(c.instructions,"\r\n");
            while(line != NULL){
                printf("Line content: %s\n", line);
                // prasing and processing logics here
                //======
                //printf("tokens:%s\n:",);
                line = strtok(NULL, "\r\n");
            }
        }
// NOTE FOR ME: Remember to call free(buffer) later in  program when  done

}   




        
    return 0;
}
int main(){
    cpu_run(0);
}