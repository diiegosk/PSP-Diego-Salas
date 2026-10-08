#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


void main() {
int fd[2];

time_t hora;
char *fecha ;
time(&hora);
fecha = ctime(&hora);


pipe(fd);


pid_t pid2 = fork();

if (pid2 == 0) {
    //Hijo (solo tiene que leer)
    close(fd[1]);


    char *fechaRecibida;


     read(fd[0], &fechaRecibida, sizeof(fechaRecibida));

     printf("Soy el proceso hijo con pid %d\n", getpid());
     printf("Fecha/hora:  %s\n", fechaRecibida);


    close(fd[0]);
    //Termina de leer

} 
else {
    //Pader (solo tiene que escribir)
    close (fd[0]);


    write(fd[1], &fecha, sizeof(fecha));


    close (fd[1]);
    //Termina de escribir

    wait(NULL);

}



}