#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo;
  pid_t pidA, ppidA;
  
  pid = fork();

  pidA = getpid();
  ppidA = getppid();


  if (pid == 0 )  
  {        
    printf("Soy el proceso HIJO \n");	  
    printf("Mi PID es: %d\n", pidA);
    printf("El PID de mi padre es: %d\n" , ppidA);
  }
  else    
  { 
   pid_hijo = wait(NULL); 
   
   printf("Soy el proceso PADRE \n");    
   printf("Mi PID es: %d\n", pidA);
   printf("PPID: %d\n", ppidA);      
  }
   exit(0);
}