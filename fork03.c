#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {

printf("Inicio\n");

pid_t pid = fork();

printf("Despues del fork\n");

if (pid == 0) {
 printf("Soy el hijo\n");
} else {
 printf("Soy el padre\n");
}

printf("Fin\n");

}

/*
Preguntas:

a) Son 2 procesos todos los que se crean

b) El proceso padre ejecuta todas las lineas menos la 16 y el proceso padre empieza desde la 11 y no ejecuta la 18

c) Los mensajes "Inicio", "Soy el hijo" y "Soy el padre" aparecerán una sola vez, sin embargo, "Después del fork" y "Fin" aparecerán 2 veces. 
Los mensajes que pueden aparecer en distinto orden serían "Soy el hijo" y "Soy el padre" que dependen de cuando se ejecuten.


*/