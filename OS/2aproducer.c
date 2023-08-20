#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,buf[3],empty=3,full=0,i,a;
  printf("Enter 1 for producer\n");
  printf("Enter 2 for consumer\n");
  printf("Enter 3 for exit\n");
  for(i=0;i>=0;i++){
    printf("Enter your choice");
    scanf("%d",&n);
  switch(n){
    case 1:
      if(empty<=3 && full<3){
        empty--;
        full++;
        printf("Process Produced,added to buffer\n"); 
        
        break;
      }
      else{
        printf("Buffer is full\n");
        break;
      }
    case 2:
        if(empty==3 && full==0){
          printf("Buffer is empty\n");
          break;
        }
        else{
          printf("Process consumed from buffer\n");
          empty++;
          full--;
          
          break;
        }
    case 3:
          exit(0);
          break;
  }
    printf("\n");
  }
}