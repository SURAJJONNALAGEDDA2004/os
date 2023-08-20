#include<stdio.h>
#include<sys/types.h>
int main(){
  pid_t pid;
  printf("\nHello world\n");
  pid=fork();
  printf("Welcome %d\n",pid);
  
}