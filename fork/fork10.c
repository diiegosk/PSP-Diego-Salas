#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid2, pid3;
  int sumas2, sumas3;

    pid2 = fork();

    if (pid2 == 0 ){

                for (int i = 0; i < 100; i++){
                sumas2 = i + 1;
                printf ("P2 %d: %d + 1 = %d \n",getpid(), i, sumas2);
            }

    } else {
        pid3 = fork();

        if (pid3 == 0) {
            
            for (int i = 100; i < 200; i++){
                sumas3 = i + 1;
                printf ("P3 %d: %d + 1 = %d \n", getpid(), i, sumas3);
            }



        }else{
            wait(NULL);
            wait(NULL);
            printf("Todos los calculos han finalizado \n");
        }

    }



    exit(0);
  
}