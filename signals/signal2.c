#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

int contador;

void signal_funcion(int signum){
  
    contador = contador + 5;
  
  printf("Han transcurrido %d segundos \n", contador);
}


int main(){
  signal(SIGUSR1,signal_funcion); 

  pid_t pid = getpid();
  while (pid != 1){

    sleep(5);
    kill(pid, SIGUSR1);
  }
  

}