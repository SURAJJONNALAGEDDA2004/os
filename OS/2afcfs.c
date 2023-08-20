#include<stdio.h>
int main(){
int bt[50],wt[50],tat[50],n,i,j,wt1=0,tat1=0 ;
printf("Enter the number of process");
scanf("%d",&n);
printf("Enter the burst times:");
for(i=1;i<=n;i++){
scanf("%d",&bt[i]);
}
wt[1]=0;
for(j=2;j<=n;j++){
wt[j]=wt[j-1]+bt[j-1];
}
for(i=1;i<=n;i++){
tat[i]=wt[i]+bt[i];
}
printf("Suraj Jonnalagedda VU21CSEN0100479");
printf("\n");
printf("FCFS Program");
printf("\n");
printf("Process\t|BT\t|WT\t|TAT");
printf("\n");
printf("----------------------");
printf("\n");
for(i=1;i<=n;i++){
printf("p%d\t\t|%d\t|%d\t|%d\t",i,bt[i],wt[i],tat[i]);
printf("\n");
}
for(i=0;i<=n;i++){
wt1=wt1+wt[i];
tat1=tat1+tat[i];
}
wt1=wt1/n;
tat1=tat1/n;
printf("avg of wt and tat is %d %d",wt1,tat1);
}