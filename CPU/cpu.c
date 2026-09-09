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
struct instructions{
      char _operator[10]; //0
      char arg1[10];     //1
      char arg2[10];     //2
      char action[10];   //3
      char end[10];      //4
};

struct instructionformat{
   char ins0[10];
   char ins1[10];
   char ins2[10];
   char ins3[10];
   char ins4[10];
//    char ext1[3];
//    char ext2[3];

};
struct extwordforinstruct{
    char ext1[3];
    char ext2[3];
};

struct CPU c = {
    .oR = {false, false, false, false, false, false, false, false},
    .Rfull = 0,
};
struct extwordforinstruct effi;
// introduced this function to reudce time wastage in writing loops
void fillRegister(int val, int i)
{       if((i-1) == -1){
          for (int i = 0; i < 8; i++) 
          {
            if (c.oR[i] == false) 
            {c.R[i] = val;
                c.oR[i] = true;
                break;
            }
          }
        if((i-1) != -1){
             c.R[i]= val;
             c.oR[i] = true;
        }
                
           }
}
// extarct no and letters from , example like J7 -> J, 7 ; R1 -> R,1
// source: https://www.google.com/search?q=how+to+extract+J+and+7+separately+in+two+variables+in+C+from+%22J7%22&sca_esv=444dee17e46a57e2&sxsrf=APpeQnsas3LaoSjPHTEjTzjqKvki9Vn42g%3A1788946108708&source=chrome.ob&fbs=ABfTbFVyMZGZf1hfvX9uKjN_-G8cxpBkeIeqYwoCbfNVc4vKE96grTuFPBRY0pmGfUF9Jyg22UXWVTXr_K4O7baggKlodDnOkiIlASZntHySiVh0bwiIMNUypEJaxFrEl8I0sOjne2qkxDLXy2NTy6FTlX-i0YI5jtw6x8Px1e5ht4KE5hM6eaUTrrz4L1UACk_d4pB2REBAHEJb5UrMvB9LeWHyWa1Gfg&vsint=&aep=1&ntc=1&cs=1&sa=X&ved=2ahUKEwjitNPKl-GWAxUGTmwGHVCgB1IQ2J8OegQIFhAD&biw=1920&bih=993&dpr=1&mstk=AUtExfArvDwH7_MMHa_rjMoXAPx9eJho2f5sxtcKYHQECjgoXkqsxI7kk1BhYFbRoIQEtl3FeOTOwIz2Pn6n2tWX2s7tni-721tzzn6NyWwCu2oiShJGsSD4hrd5TqJ9tk9PQj7So23RPPtVv39v5Ls5mSWrIUoeNdD0-xnk3J4Ba2WPCfD1n6zbHNTPuhz6aHHA4op4W_nlj1aJ9jeNe2RasLb8r-BmbP4BdwrSt4qw3_mg-R-POJv4ECYiAkhdUBe2VJDkMtZPw371oUXiAtwGygbye_DusvGluktwEV4ZmGzIodGb3eUU7iVYKl9G_OFLQFj4yJ5DRiZrog&csuir=1&atvm=2&mtid=yiahasX1II2dseMPhcztiAo&udm=50
void ew(char word[]){
  sscanf(word, "%c%c", &effi.ext1[0], &effi.ext2[0]);
  effi.ext1[1] = '\0';
  effi.ext2[1] = '\0';
}

int ArithematicUnit(const char *type, unsigned int a, unsigned int b, int des)
{
    if (strcmp("add", type) == 0)
    {
        struct addition r = addnum(a, b);

        // for (int i = 0; i < 8; i++) {
        //     if (c.oR[i] == false) {
        //         c.R[i] = r.sum;
        //         c.oR[i] = true;
        //         break;
        //     }
        fillRegister(r.sum, des);
        
    } else if (strcmp("sub", type) == 0) {
        struct subtraction r = subnum(a, b);

        // for (int i = 0; i < 8; i++)
        // {
        //     if (c.oR[i] == false)
        //     {
        //         c.R[i] = r.result;
        //         c.oR[i] = true;
        //         break;
        //     }
        // }
        fillRegister(r.result,des);
    } else {
        printf("[DEBUG, cpu.c] unknown arithmetic input \"%s\" ", type);
    }

    return 0;
}


/*
structure :/
0 : 
1: operator, 
2: number,
3: number,
4: next line, jump , end/exit/turn off

i know the way this is made is not an optimised approach but currently i don't have much of time to 
figure things out much deeply, i will try to optimise it later after watching few tutorials to make this as it is not that easy.BUT NOT IMPOSSIBLE THOUGH
*/
// i don't know how but just by adding '*' fixed the issue
int interpreter(char *ins0, char *ins1, char *ins2, char *ins3, char *ins4){
    struct instructionformat ift;
  //block for ins0, all keywords   
    if(strcmp(ins0,"ADD")==0){
        //taking example ADD 2 2 STORE R1
        // if(){

        // }
        unsigned int a = atoi(ins1);
        unsigned int b = atoi(ins2);
        struct addition r = addnum(a, b);
        if(strcmp(ins3, "STORE")==0)
        {
              if(strcmp(effi.ext1, "R")==0){
                fillRegister(r.sum,atoi(effi.ext2));
                printf("stored '%i' at %i",atoi(effi.ext1), atoi(effi.ext2));
              }
        }
        if(strcmp(ins4,"HALT")==0){
            printf("off");
            exit(EXIT_SUCCESS); // i guess it will stop there
        } else if(strcmp(ins4,effi.ext1)==0){
                if(strcmp(effi.ext1, "J")==0){
                    printf("not implemented yet");
                } //else if(strcmp(effi.ext1, "R")==0){
                     
                // }
                // doing that much for additon was so time taking it took 37 minutes
                // just copy and paste below and made some changes if needed from above
        }
        
    }
    else if(strcmp(ins0,"SUB")==0){
        unsigned int a = atoi(ins1);
        unsigned int b = atoi(ins2);
        struct subtraction r = subnum(a, b);
        if(strcmp(ins3, "STORE")==0)
        {
              if(strcmp(effi.ext1, "R")==0){
                fillRegister(r.result,atoi(effi.ext2));
                printf("stored '%i' at %i",atoi(effi.ext1), atoi(effi.ext2));
              }
        }
        if(strcmp(ins4,"HALT")==0){
            printf("off");
            exit(EXIT_SUCCESS); // i guess it will stop there
        } else if(strcmp(ins4,effi.ext1)==0){
                if(strcmp(effi.ext1, "J")==0){
                    printf("not implemented yet");
                } //else if(strcmp(effi.ext1, "R")==0){
                     
                // }
                // doing that much for additon was so time taking it took 37 minutes
        }
    }
    else if(strcmp(ins0,"DIV")==0){
        // will be implemented probably in next update when division will be added
    //     unsigned int a = atoi(ins1);
    //     unsigned int b = atoi(ins2);
    //     struct addition r = addnum(a, b);
    //     if(strcmp(ins3, "STORE")==0)
    //     {
    //           if(strcmp(effi.ext1, "R")==0){
    //             fillRegister(r.sum,atoi(effi.ext2));
    //           }
    //     }
    //     if(strcmp(ins4,"HALT")==0){
    //         printf("off");
    //         EXIT_SUCCESS; // i guess it will stop there
    //     } else if(strcmp(ins4,effi.ext1)==0){
    //             if(strcmp(effi.ext1, "J")==0){
    //                 printf("not implemented yet");
    //             } //else if(strcmp(effi.ext1, "R")==0){
                     
    //             // }
    //             // doing that much for additon was so time taking it took 37 minutes
    //     }
     }
    else if(strcmp(ins0,"MUL")==0){
        // will be implemented probably in next update when multiplication will be added
        // unsigned int a = atoi(ins1);
        // unsigned int b = atoi(ins2);
        // struct addition r = addnum(a, b);
        // if(strcmp(ins3, "STORE")==0)
        // {
        //       if(strcmp(effi.ext1, "R")==0){
        //         fillRegister(r.sum,atoi(effi.ext2));
        //       }
        // }
        // if(strcmp(ins4,"HALT")==0){
        //     printf("off");
        //     EXIT_SUCCESS; // i guess it will stop there
        // } else if(strcmp(ins4,effi.ext1)==0){
        //         if(strcmp(effi.ext1, "J")==0){
        //             printf("not implemented yet");
        //         } //else if(strcmp(effi.ext1, "R")==0){
                     
        //         // }
        //         // doing that much for additon was so time taking it took 37 minutes
        // }
    }
    else if(strchr(ins0,'R') != NULL){
     printf("not implemented yet");
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

// update readme file for line no
//it was really painful to deal with tokenisation loops so i chnaged it quite a bit like it was a whole lot of change
int tokeassigner(char *line)
{   
    struct instructions it; //so that at the end it get free on its own
    char *operator;
    char *arg1;
    char *arg2;
    char *action;
    char *destination;

    operator = strtok(line, " ");
    arg1 = strtok(NULL, " ");
    arg2 = strtok(NULL, " ");
    action = strtok(NULL, " ");
    destination = strtok(NULL, " ");

    //printf("Operator: %s\n", operator);
    strcpy(it._operator,operator);
    //printf("Argument 1: %s\n", arg1);
    strcpy(it.arg1, arg1);
    //printf("Argument 2: %s\n", arg2);
    strcpy(it.arg2, arg2);
    //printf("Action: %s\n", action);
    strcpy(it.action, action);
    //printf("Destination: %s\n", destination);
    strcpy(it.end, destination);
    ew(destination);
    interpreter(it._operator,it.arg1,it.arg2, it.action, it.end);
    
    return 0;
}

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
            //buffer = c.instructions; --> this was the issue 
            //fixed :
            strcpy(c.instructions, buffer);
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
                tokeassigner(line);
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
