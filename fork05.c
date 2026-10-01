#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid;

    pid = fork();

    if (pid == 0 ){

         pid = fork();

         if (pid== 0){

            printf("Soy el proceso 3 ");
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre es: %d\n" , getppid());

         } else {
            
            wait(NULL);
            printf("Soy el proceso 2 ");
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre es: %d\n" , getppid());
         }

    } else {

        wait(NULL);
        printf("Soy el proceso 1 ");
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi hijo es: %d\n" , pid);
    }

    exit(0);
  
}