#include<stdio.h>
int main(){
  int at[50],bt[50],rt[50],endtime,i,smallest,remain=0,n,time,swt=0,stat=0;
  printf("Enter the no of process:");
  scanf("%d",&n);
  printf("Enter the arrival times:");
  for(i=0;i<n;i++){
    scanf("%d",&at[i]);
  }
  printf("Enter the burst times:");
  for(i=0;i<n;i++){
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }
  rt[9]=9999;
  printf("\nprocess\t|arrivaltime\t|burstime\t|waitingtime\t|turnaroundtime");
  for(time=0;remain!=n;time++){
    smallest=9;
    for(i=0;i<n;i++){
      if(at[i]<=time&&rt[i]<rt[smallest]&&rt[i]>0){
        smallest=i;
      }
    }
    rt[smallest]--;
    if(rt[smallest]==0){
      remain++;
      endtime=time+1;
      printf("p[%d]\t\t|%d\t|%d\t|%d\t|%d\t|",smallest+1,at[i],bt[i],endtime-bt[smallest]-at[smallest],endtime-at[smallest]);
      swt+=endtime-bt[smallest]-at[smallest];
      stat+=endtime-at[smallest];
    }
  }
  printf("\nAverage waiting time is %f",(swt*1.0)/n);
  printf("Average turn around time is %f",(stat*1.0)/5);
}