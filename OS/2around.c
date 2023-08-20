#include<stdio.h>
int main()
{
  int i,n,j,t,r,flg=0,tq,wt=0,tat=0,at[10],bt[10],rt[10];
  printf("Enter number of Process:\t ");
  scanf("%d",&n);
  r=n;
  printf("Enter Arrival Time");
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
  }
  printf("Enter Burst Time ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("Suraj Jonnalagedda VU21CSEN0100479\n");
  printf("ROUND ROBIN Program\n");
  printf("Process\t|Bt\t|TAT|Wt\n");
  printf("-------------------------------------\n");
  for(t=0,i=0;r!=0;)
  {
    if(rt[i]<=tq&&rt[i]>0)
    {
      t+=rt[i];
      rt[i]=0;
      flg=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=tq;
      t+=tq;
    }
    if(rt[i]==0&&flg==1)
    { 
      r--;
      printf("p%d\t\t|%d\t|%d\t|%d\t",i,bt[i],t-at[i],t-at[i]-bt[i]);
      printf("\n");
      wt+=t-at[i]-bt[i];
      tat+=t-at[i];
      flg=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=t)
      i++;
    else
      i=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Average Turnaround Time = %f",tat*1.0/n);
  return 0;
}
