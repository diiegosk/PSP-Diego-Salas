#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void main() {

int fd[2];
pipe(fd);


pid_t pid2 = fork();

if (pid2 == 0) {
    //Hijo (solo tiene que leer)
    close(fd[1]);

    int numeroRecibido;
    int totalsuma;

    while  (read(fd[0], &numeroRecibido, sizeof(numeroRecibido)) > 0){
        totalsuma = totalsuma + numeroRecibido;
        printf("Numero:  %d\n", numeroRecibido);
    }
     
    printf ("Total: %d\n",totalsuma);
    close(fd[0]);
    //Termina de leer

} 
else {
    //Padre (solo tiene que escribir)
    close (fd[0]);

        char caracterEntrada[20];
        

        do{
        printf("Escribe un numero, pulsa + para parar \n");
        scanf("%s", caracterEntrada);

            if(strcmp(caracterEntrada, "+")!=0){
            int numero = atoi (caracterEntrada);
            write(fd[1], &numero, sizeof(numero));

            }
            

        } while (strcmp(caracterEntrada, "+")!=0);


    


    close (fd[1]);
    //Termina de escribir

    wait(NULL);

}



}