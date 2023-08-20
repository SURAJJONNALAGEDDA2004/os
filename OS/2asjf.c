
#include<stdio.h>
int main()
{
  int bt[100],tmp[100],wt[100],at[100],tat[100],k,i,j,n,tot=0;
  float temp=0,twt=0,ttat=0,awt=0,atat=0;
  printf("\nEnter the number of processes:");  
  scanf("%d",&n);
  printf("\nEnter the Arrival Times:");  
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
  }   
  printf("\nEnter the Burst Times:");  
  for(i=0;i<n;i++)
  {
    tmp[i]=i+1;
    scanf("%d",&bt[i]);
  } 
  
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(bt[j]>bt[j+1])
      {
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
    if(i!=1)
    {
      for(j=i-1;j>=0;j--)
      {
        if(at[i]<at[j])
        {
          tot=tot+bt[j];
        }
        else
        {
          tot=tot-bt[j];
        }
      }
   if(tot>=0)
   { 
      wt[i]=tot;
      tat[i]=wt[i]+bt[i];
      tot=0;
    }
    else
    {
      tot=0; 
      for(k=i-1;k>=0;k--)
      {
       tot=tot+bt[k];
      }
      tot=tot-at[i];
      wt[i]=tot;
      tat[i]=wt[i]+bt[i];
      tot=0;
    } 
    }
    else
    {
      if(bt[i]==bt[i-1])
      {
        wt[i]=bt[i-1];
        tat[i]=wt[i]+bt[i];
      }
      else
      {
        wt[i]=bt[i]-(bt[i-1]-at[i-1]);
        tat[i]=wt[i]+bt[i];
      }
    }
  }
  printf("Suraj Jonnalagedda VU21CSEN0100479\n");
  printf("SJF Program \n");
  printf("---------------------------------------------\n");
  printf("Process\t|At\t|Bt\t|Wt\t|Tat\t\n");
  for(i=0;i<n;i++)
    {
      printf("p%d\t\t|%d\t|%d\t|%d\t|%d\t",i,at[i],bt[i],wt[i],tat[i]);
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
  printf("\nAverage Waiting Time= %f",awt);
  printf("\nAverage Turn Around Time= %f",atat);
}

