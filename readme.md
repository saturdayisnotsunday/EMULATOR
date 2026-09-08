<p align="center">
  <img src="./banr.png" width="100%" alt="Header Banner" />
</p>
# EMULATOR

A custom CPU emulator and bare-metal software stack built from first principles.

This project explores what happens when the CPU, ISA, assembler, memory model,
and operating system are all designed together rather than targeting an existing
architecture.

The current system begins with a binary CPU model and is being extended toward
a quaternary architecture, where each computational digit can represent one of
four states.

The goal is not simply to emulate an existing processor, but to understand the
boundary between hardware architecture and the software that depends on it.


used google for:
    
  [+]  printf("Result of %u + %u = %u\n", a, b, r.sum);
    // NOTE: i need to know about undeflow using google
    if (b > a) {
        sb.underflow = 1; // Underflow/Borrow occurred  
    } else {
        sb.underflow = 0; // Safe subtraction
    }


 [+]   char *line = strtok(c.instructions,"\r\n");
    
 [+]   strchr

Took help of chatgpt for:
-> To understand how to redesign components and setup cpu.c to be made as a     callable function type to motherboard.c
-> redegined strcutre insdie cpu.c by learning from the above stated
-> tokenising at line no 60 at present of this commit
-> i dropped the above tokenisation idea and tired to deduce how to do it and came up with using the strtok the theory is clear and i explained it to chatgpt and asked for minimal exact syntax(line 69 whic which was line 60 previously)
Took help from this source:[text](https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c)    for effectively getting a file reading program in C