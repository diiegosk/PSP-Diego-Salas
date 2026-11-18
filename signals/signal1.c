#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

void fun_signal(int sig){
  time_t t = time(NULL);
  time(&t);
  pid_t pid = getpid();
  printf("Fin del proceso %d : %s \n", pid, ctime(&t));
}


int main(){
  signal(SIGINT,fun_signal); 

  time_t t = time(NULL);
  time(&t);
  pid_t pid = getpid();
  printf("Inicio del proceso %d : %s \n", pid, ctime(&t));

  pause();

}