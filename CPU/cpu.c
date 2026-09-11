//#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alu.h"
#include <ctype.h>


// struct(s) begins ===================================================
struct CPU {
    int R[8];
    bool oR[8];
    int Rfull;
    char *instructions; //overflow took an hour to debug that is cause segment fault issue
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
};
struct extwordforinstruct{
    char ext1[3];
    char ext2[3];
};
// struct(s) over ===================================================


// struct(s) declaration begins ===================================================
struct CPU c = {
    .oR = {false, false, false, false, false, false, false, false},
    .Rfull = 0,
};
struct extwordforinstruct effi;
// struct(s) declaration over ===================================================



// all voids starts ========================================================================================
void fillRegister(int val, int i){

 if(c.oR[i]==true ){
    printf("[DEBUG, cpu.c fillREgister] error_type: RESGISTER_FULL couldn't save value at R[%i]  it contains '%i'\n",i,c.R[i]);
    exit(EXIT_FAILURE);
 } else if(i>7){
    printf("[DEBUG, cpu.c fillREgister] error_type: REGISTER_NOT_FOUND couldn't save value at R[%i]\n",i);
    exit(EXIT_FAILURE);
 }else{
    c.oR[i] = true;
    c.R[i] = val;
 }

}
// extarct no and letters from , example like J7 -> J, 7 ; R1 -> R,1
// source: https://www.google.com/search?q=how+to+extract+J+and+7+separately+in+two+variables+in+C+from+%22J7%22&sca_esv=444dee17e46a57e2&sxsrf=APpeQnsas3LaoSjPHTEjTzjqKvki9Vn42g%3A1788946108708&source=chrome.ob&fbs=ABfTbFVyMZGZf1hfvX9uKjN_-G8cxpBkeIeqYwoCbfNVc4vKE96grTuFPBRY0pmGfUF9Jyg22UXWVTXr_K4O7baggKlodDnOkiIlASZntHySiVh0bwiIMNUypEJaxFrEl8I0sOjne2qkxDLXy2NTy6FTlX-i0YI5jtw6x8Px1e5ht4KE5hM6eaUTrrz4L1UACk_d4pB2REBAHEJb5UrMvB9LeWHyWa1Gfg&vsint=&aep=1&ntc=1&cs=1&sa=X&ved=2ahUKEwjitNPKl-GWAxUGTmwGHVCgB1IQ2J8OegQIFhAD&biw=1920&bih=993&dpr=1&mstk=AUtExfArvDwH7_MMHa_rjMoXAPx9eJho2f5sxtcKYHQECjgoXkqsxI7kk1BhYFbRoIQEtl3FeOTOwIz2Pn6n2tWX2s7tni-721tzzn6NyWwCu2oiShJGsSD4hrd5TqJ9tk9PQj7So23RPPtVv39v5Ls5mSWrIUoeNdD0-xnk3J4Ba2WPCfD1n6zbHNTPuhz6aHHA4op4W_nlj1aJ9jeNe2RasLb8r-BmbP4BdwrSt4qw3_mg-R-POJv4ECYiAkhdUBe2VJDkMtZPw371oUXiAtwGygbye_DusvGluktwEV4ZmGzIodGb3eUU7iVYKl9G_OFLQFj4yJ5DRiZrog&csuir=1&atvm=2&mtid=yiahasX1II2dseMPhcztiAo&udm=50
void ew(char word[]) {
    int len = strlen(word); //some thing magical
    // Safety check: ensure that string has at least a letter and a number
    if (len < 2)
    {
        return; 
    }
    effi.ext1[0] = word[0];        // always takes the first character ('J')
    effi.ext2[0] = word[len - 1];  // the last character ('1', '7', or '3')
    effi.ext1[1] = '\0';
    effi.ext2[1] = '\0';
}

void rest(char *ins3, char *ins4, int resultval){
       if(strcmp(ins3, "STORE")==0)
        {
              ew(ins4); 
              if(strcmp(effi.ext1, "R")==0){
                fillRegister(resultval,atoi(effi.ext2));
                printf("[DEBUG, cpu.c , rest()]stored '%i' at R%i\n",resultval, atoi(effi.ext2));
                //return;
              }
        }
        if(strcmp(ins4,"HALT")==0){
            printf("[DEBUG, cpu.c , rest()] off\n");
            
            exit(EXIT_SUCCESS); // i guess it will stop there
        } else if(strcmp(ins4,effi.ext1)==0){
                if(strcmp(effi.ext1, "J")==0){
                    printf("[DEBUG, cpu.c , rest()] not implemented yet\n");
                } //else if(strcmp(effi.ext1, "R")==0){
                     
                // }
                // doing that much for additon was so time taking it took 37 minutes
                // just copy and paste below and made some changes if needed from the above
        }
}


// all voids over ========================================================================================


/*
structure :/
0:operand
1: argument 1
2: argument 2
3: action with the result
4: final end 

i know the way this is made is not an optimised approach but currently i don't have much of time to 
figure things out much deeply, i will try to optimise it later after watching few tutorials to make this as it is not that easy.BUT NOT IMPOSSIBLE THOUGH
*/

/*
## let's define new instructions ##
- ADD/SUB/DIV/MUL 2 2 STORE R1
- ADD R1 R2 STORE R3
- FREE R1
*/

// i don't know how but just by adding '*' it fixed the issue
unsigned int arithematicunit(const char *type, unsigned int a, unsigned int b){
    if (strcmp(type, "ADD") == 0) {
        return addnum(a, b).sum;
    }
    if (strcmp(type, "SUB") == 0) {
        return subnum(a, b).result;
    }
    if (strcmp(type, "DIV") == 0) {
        return divnum(a, b).divres;
    }
    if (strcmp(type, "MUL") == 0) {
        return mulnum(a, b).mulres;
    }

    return 0;
}

/* R<number> and J<number> are operand references, not numeric literals. */
static bool is_register_or_jump(const char *operand)
{
    size_t i;

    if ((operand[0] != 'R' && operand[0] != 'J') || operand[1] == '\0') {
        return false;
    }

    for (i = 1; operand[i] != '\0'; i++) {
        if (!isdigit((unsigned char)operand[i])) {
            return false;
        }
    }

    return true;
}

int interpreter(char *ins0, char *ins1, char *ins2, char *ins3, char *ins4){
    struct instructionformat ift;
    int a = atoi(ins1);
    int b = atoi(ins2);
    bool a_is_reference = false;
    bool b_is_reference = false;

    /* atoi returns 0 for 0 and for non-numeric operands, so inspect Rn/Jn. */
    if (a == 0) {
        a_is_reference = is_register_or_jump(ins1);
    }
    if (b == 0) {
        b_is_reference = is_register_or_jump(ins2);
    }

 if(!a_is_reference && !b_is_reference){
    unsigned int result = arithematicunit(ins0, (unsigned int)a, (unsigned int)b);

    rest(ins3, ins4, result);
 } else if(a_is_reference || b_is_reference){
     unsigned int a_val, b_val;

     if (a_is_reference) {
         ew(ins1);
         a_val = c.R[atoi(effi.ext2)];
         printf("R[%i] contains '%i'\n",atoi(effi.ext2), c.R[atoi(effi.ext2)]);
     } else {
         a_val = (unsigned int)a;   // reuse the atoi(ins1) result already computed above
     }

     if (b_is_reference) {
         ew(ins2);
         b_val = c.R[atoi(effi.ext2)];
         printf("R[%i] contains '%i'\n",atoi(effi.ext2), c.R[atoi(effi.ext2)]);
     } else {
         b_val = (unsigned int)b;   // reuse the atoi(ins2) result alrady computed above
     }

     unsigned int result = arithematicunit(ins0, a_val, b_val);
     printf("passed ins3:%s,ins4:%s\n", ins3, ins4);
     rest(ins3, ins4, result);
 if(strcmp(ins0,"FREE")^(strcmp(ins1, "0")==0)^(strcmp(ins2, "0")==0)^(strcmp(ins3, "0")==0)^(strcmp(ins4, "0")==0))
 {
    printf("FREE block starts\n");
    ew(ins1);
    c.oR[atoi(effi.ext2)] = false;
    printf("[DEBUG, cpu.c,interpreter] freed R[%i]\n", atoi(effi.ext2));
 }

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

//it was really painful to deal with tokenisation loops so i changed it quite a bit like it was a whole lot of change
int tokeassigner(char *line)
{   
    
    struct instructions it; //so that at the end it get free on its own
    char *operator;
    char *arg1;
    char *arg2;
    char *action;
    char *destination;
    char *token_save;

    operator = strtok_r(line, " ", &token_save);
    arg1 = strtok_r(NULL, " ", &token_save);
    arg2 = strtok_r(NULL, " ", &token_save);
    action = strtok_r(NULL, " ", &token_save);
    destination = strtok_r(NULL, " ", &token_save);

    
    strcpy(it._operator,operator);
    
    strcpy(it.arg1, arg1);
    
    strcpy(it.arg2, arg2);
    
    strcpy(it.action, action);
    
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
        long line_Count;
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
                if(bytesRead>0){
                    line_Count = 1;
                    for(size_t i = 0;i<bytesRead;i++)
                    {
                        if(buffer[i] == '\n'){
                            line_Count++;
                        }
                    }
                }
            }
            else 
            {
        
                fprintf(stderr, "[DEBUG, cpu.c , cpu_run()]Error: Memory allocation failed.\n");
            }
            
            fclose (f);
            printf("[DEBUG, cpu.c , cpu_run()] content: %s\n", buffer);
            //buffer = c.instructions; --> this was the issue 
            //fixed :
            //strcpy(c.instructions, buffer);
            c.instructions = buffer;
        }
        else 
        {
          fprintf(stderr, "[DEBUG, cpu.c , cpu_run()] Error: Could not open file.\n");
        }
        // now main work starts from here 

        if (buffer){
         char *line_save;
         char *line = strtok_r(c.instructions, "\r\n", &line_save);
         while (line != NULL) {
         printf("Line content: %s\n", line);
         printf("[DEBUG, cpu.c, cpu_run()] given to token assinger: %s\n", line);
         tokeassigner(line);
         line = strtok_r(NULL, "\r\n", &line_save);
        } 
        }
        }
        
         
    return 0;
}
