#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
 wait(NULL);
 pid2 = fork();
wait(NULL);
 printf("CCC \n");
 }
 exit(0);
}

/* 

b) La salida que genera es AAA, BBB, CCC, CCC. Si que puede salir otra salida si 
el proceso padre se ejecuta primero y el primer hijo todavia no se ha ejecutado.


*/