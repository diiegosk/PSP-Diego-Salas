#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 sleep(1);   
 printf("AAA \n");
 } else printf("BBB \n");
 exit(0);
}

/*
Preguntas

b) la salida es CCC AAA BBB, si que podria salir otra salida, si el proceso hijo no lo imprime antes que el padre, este se A y B se imprimirian al reves

*/