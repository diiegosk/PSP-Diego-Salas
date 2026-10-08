#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2, pid3, pid4;

    pid1 = fork();

if(pid1 == 0){

    printf ("P2 comienza \n");
    sleep (5);
    printf ("P2 acaba \n");

    
}else{

    pid2 = fork();

            if(pid2 == 0){

            printf ("P3 comienza \n");
            sleep (2);
            printf ("P3 acaba \n");
            

        }else{
            
                pid3 = fork();
            
                if(pid3 == 0){

                
                    printf ("P4 comienza \n");
                    sleep (4);
                    printf ("P4 acaba \n");

                }else{
                    pid4 = fork();
                }

            wait(NULL);
        }

        wait(NULL);
    }

    wait(NULL);

 exit(0);
}

