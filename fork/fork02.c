#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo, pidA;
  
  pid = fork();
  pidA = getpid();


  if (pid == 0 )  
  {        
    printf("Diego Salas");
  }
  else    
  { 
   pid_hijo = wait(NULL); 
     
   printf("Mi PID es: %d\n", pidA);
   printf("El PID de mi hijo es: %d\n", pid_hijo);      
  }
   exit(0);
}