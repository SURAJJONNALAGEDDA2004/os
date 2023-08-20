#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
  char buf[50];
  read(0,buf,15);
  printf("\nWriting\n");
  write(1,buf,10);
  printf("\n buffer has %s\n",buf);
  return 0;
}