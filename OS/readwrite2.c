#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
  int fd,sz;
  char * c =(char *)calloc(10000, sizeof(char));
  fd= open("new1.txt",O_RDONLY);
  if(fd<0){
    perror("r1");
    exit(1);
  }
  sz=read(fd,c,100);
  c[sz]='\0';
  printf("\nOUTPUT : \n %s \n",c);
  close(fd);
  fd= open("new2.txt",O_WRONLY);
  write(fd,c,100);
  close(fd);
}
