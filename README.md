<img src="http://image3.mouthshut.com/images/imagesp/925718051s.png"  width="120" height="100"/>

## Unix Systems Programming and Compiler Design Lab (VTU 10CSL68)

### List of Experiments for USP : Design, develop, and execute the following programs  
1.  [Write  a  C/C++  POSIX  compliant  program  to  check  the following limits:    (i) No. of clock ticks (ii)  Max.  no. of  child  processes    iii) Max. path length  (iv) Max. no. of characters in a file name    (v)   Max. no. of open files process ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/1.c)    

2.  [Write a C/C++ POSIX compliant program that prints the POSIX defined configuration options supported on any given system using feature test macros.](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/2.c)    

3. [Consider the last 100 bytes as a region. Write a C/C++  program  to check  whether  the  region  is  locked  or  not.  If  the  region  is  locked,print pid of the process which has locked. If the region is not locked, lock  the  region  with  an  exclusive  lock,  read  the  last  50  bytes  and unlock the region. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/3.c)

4.  [Write a C/C++ program which demonstrates interprocess communication between a reader process and a writer process.  Use mkfifo, open, read, write and close APIs in your program. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/4.c)

5.  a. [Write a C/C++ program that outputs the contents of its Environment list ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/5a.c)    
    b. [Write a C / C++ program to emulate the unix ln command ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/5b.c)

6.  [Write a C/C++ program to illustrate the race condition. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/6.c)

7.  [Write a C/C++ program that creates a zombie and then calls system to execute the ps command to verify that the process is zombie. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/7.c)

8.  [Avoid Zombie Process by Forking Twice](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/8.c)

9.  [Write a C/C++ program to implement the system function. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/9.c)

10. [Write a C/C++ program to set up a real-time clock interval timer using the alarm API. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/10.c)      
 
### List of Experiments for Compiler Design : Design, develop, and execute the following programs  

11. [Write a C program to implement the syntax-directed definition of “if E then S1” and “if E then S1 else S2”.(Refer Fig.8.23 in the text book prescribed for 06CS62 Compiler Design, Alfred V Aho, Ravi Sethi, and Jeffrey D Ullman: Compilers- Principles, Techniques and Tools, 2nd Edition, Pearson Education, 2007). ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/11.c)

12. [Write a yacc program that accepts a regular expression as input and produce its parse tree as output. ](https://raw.githubusercontent.com/Akhilsudh/10CSL68/master/12.y)

### Compiling the code
For C programs
    
    gcc file.c
    
For YACC programs

    yacc -d file.y
    gcc y.tab.c
    
### Executing the  code

    ./a.out argument1 argument2 #All the arguments required to run a given program 
