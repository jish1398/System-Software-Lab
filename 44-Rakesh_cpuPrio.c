#include<stdio.h>
void main()
{
  int bt[20],dup[20],atat=0,awt=0,wt[20],tat[20],i,j,n,temp,prio[20];
  printf("Enter no.of processes: ");
  scanf("%d",&n);
  printf("\n\nBurst time and Priority of: \n" );
  wt[0] = 0;
  for(i = 0; i < n; i++) {
        printf("\t\tP[%d]: ",i+1);
        scanf("%d %d",&bt[i],&prio[i]);

        dup[i] = i;
  }
  for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
    {
       if(prio[j]>prio[j+1])
       {
          temp=prio[j];
          prio[j]=prio[j+1];
          prio[j+1]=temp;
          temp=bt[j];
          bt[j]=bt[j+1];
          bt[j+1]=temp;
          temp=dup[j];
          dup[j]=dup[j+1];
          dup[j+1]=temp;
       }
    }
tat[0] = bt[0];
for(i = 1; i < n ; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++) {
                wt[i] += bt[j];
        }

        tat[i] = bt[i] + wt[i];
}
  printf("\n\n\t\t+---------------+---------------+---------------+---------------+\n");
  printf("\t\t|    Process\t|   Priority\t| Waiting Time\t|TurnAround Time|\n");
  printf("\t\t+---------------+---------------+---------------+---------------+\n");
for(i = 0; i < n; i++) {
  printf("\t\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",dup[i]+1,prio[i],wt[i],tat[i]);
        awt += wt[i];
        atat += tat[i];
}
printf("\t\t+---------------+---------------+---------------+---------------+\n");
printf("\t\t|Average Waiting Time\t\t|\t\t%.2f\t\t|\n", (float)awt/n);
printf("\t\t+-------------------------------+-------------------------------+\n");
printf("\t\t|Average TurnAround Time \t|\t\t%.2f\t\t|\n",(float)atat/n);
printf("\t\t+-------------------------------+-------------------------------+\n");

}

