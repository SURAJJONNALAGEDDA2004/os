#include<stdio.h>
int main()
{
  int bt[30],pri[30],tmp[30],wt[30],at[30],tat[30],i,j,n,tot=0,temp;
  float twt=0,ttat=0,awt=0,atat=0;
  printf("number of processes :");  
  scanf("%d",&n);
  printf("\nEnter burst times :");  
  for(i=0;i<n;i++)
  {
    tmp[i]=i+1;
    scanf("%d",&bt[i]);
  } 
  printf("enter priorities :\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&pri[i]);
  } 
  printf("enter the arrival times :\n");  
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
  }   
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(pri[j]>pri[j+1])
      {
        temp=pri[j];
        pri[j]=pri[j+1];
        pri[j+1]=temp;
        temp=bt[j];
        bt[j]=bt[j+1];
        bt[j+1]=temp;
        temp=tmp[j];
        tmp[j]=tmp[j+1];
        tmp[j+1]=temp;
        temp=at[j];
        at[j]=at[j+1];
        at[j+1]=temp;
      }
    }
  } 
  wt[0]=0;
  tat[0]=wt[0]+bt[0];
  for(i=1;i<n;i++)
  {
    tot=0;
    for(j=i-1;j>=0;j--)
    {
      tot=tot+bt[j];
    }
    tot=tot-at[i];
    if(i==1)
    {
      wt[i]=bt[i-1];
      tat[i]=bt[i]+wt[i];  
    }
    else
    {
      wt[i]=tot;
      tat[i]=bt[i]+wt[i];
    }
  }
  printf("------------------------------------------------------\n");
  printf("Suraj Jonnalagedda VU21CSEN0100479\n");
  printf("Priority Scheduling Program\n");
  printf("------------------------------------------------------\n");
  printf("Process\t Arrivaltime\t Bursttime\t Waitingtime\t Turn around time\t\n");
  for(i=0;i<n;i++)
  {
    printf("p%d\t\t %d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\t\t\t\t\t\t",i,at[i],bt[i],wt[i],tat[i]);
    printf("\n");
  }
  for(i=0;i<n;i++)
    {
      twt=twt+wt[i];
    }
  for(i=0;i<n;i++)
    {
      ttat=ttat+tat[i];
    }
  awt=twt/n;
  atat=ttat/n;
  printf("\nAverage wt is %f",awt);
  printf("\nAverage TaT is %f",atat);
}
