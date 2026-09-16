<p align="center">
  <img src="./banr.png" width="100%" alt="Header Banner" />
</p>

<h1 align="center"><b>EMULATOR</b></h1>


A custom CPU emulator and bare-metal software stack built from first principles.

This project explores what happens when the CPU, ISA, assembler, memory model,
and operating system are all designed together rather than targeting an existing
architecture.

The current system begins with a binary CPU model and is being extended toward
a quaternary architecture(if research went successful), where each computational digit can represent one of four states.

The goal is not simply to emulate an existing processor, but to understand the
 hardware architecture and the software that depends on it.

<details>
<summary><b>Used Google for</b></summary>
<br>
<p align="center">

    [+]  printf("Result of %u + %u = %u\n", a, b, r.sum);
         // NOTE: i need to know about undeflow using google
         if (b > a) {
          sb.underflow = 1; // Underflow/Borrow occurred  
         } else {
             sb.underflow = 0; // Safe subtraction
         }


    [+]   char *line = strtok(c.instructions,"\r\n");
    
    [+]   strchr
    [+] the newly created em(); function i do not know C that much so i sometimes needs help for little advance things like "\0' was unknown to me and so the sscanf()
    [+] for the new update in ew fucntion to support inputs like J123 for 'J' and atoi('123')
</p>

</details>
    

<details>
<summary><b>Used Chatgpt for</b></summary>
<br>
<p align="center">

     [+] To understand how to redesign components and setup cpu.c to be made as a     callable function type to motherboard.c
     [+] redegined strcutre insdie cpu.c by learning from the above stated
     [+] tokenising at line no 60 at present of this commit
     [+] i dropped the above tokenisation idea and tired to deduce how to do it and came up with using the strtok the theory is clear and i explained it to chatgpt and asked for minimal exact syntax(line 69 whic which was line 60 previously)
     [+]Took help from this source:[text](https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c)    for effectively getting a file reading program in C
     [+] run cpu_run() function in motherboard.c as it used something unexpected and which i never knew

</p>

</details>

<details>
<summary><b>Used Claude for</b></summary>
<br>
<p align="center">
  
    [+] to debug the issue for why loop was not woking it was due to wrong conditioning of k==line_Count it should be < not ==

    
</p>

</details>

<details>
<summary><b>Issues </b></summary>
<br>
<p align="center">
  
    Now the real issue left is to implement RAM(emulated) so it will be taking enough of time, the 
    use is clear but the problem is how to implement in C syntx + enabling cpu.c to access it through motherboard.c

    
</p>

</details>

# Engineering Architecture & Log Book 
Click the dropdown below to view my complete system reasoning, design hypotheses, and low-level debugging logs directly:

<details>
<summary><b>Expand to read the Log Book</b></summary>
<br>
<p align="center">
  <img src="./banr.png" width="100%" alt="Header Banner" />
</p>

</details>



https://github.com/saturdayisnotsunday/EMULATOR
