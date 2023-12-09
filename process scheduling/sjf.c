#include<stdio.h>
#include<stdlib.h>
float atat=0,awt=0;
void sortAt(int p[],int at[],int bt[],int n);

void swap(int *x, int *y);

void swap(int *x, int *y)
{
      int temp = *x;
      *x=*y;
      *y=temp;
}

void sortAt(int p[],int at[],int bt[],int n)
{
      int i,j;
      for(i=0;i<n;i++)
      {
            for(j=i+1;j<n;j++)
            {
                  if(at[i]>at[j])
                  {
                        swap(&p[i],&p[j]);
                        swap(&at[i],&at[j]);
                        swap(&bt[i],&bt[j]);
                  }
                  else if(at[i]==at[j])
                  {
                        if(bt[i]>bt[j])
                        {
                              swap(&p[i],&p[j]);
                              swap(&at[i],&at[j]);
                              swap(&bt[i],&bt[j]);
                        }
                  }
            }
      }
}

void calc(int ct[],int at[],int bt[],int tat[],int wt[],int n)
{
      int i;
      for(i=0;i<n;i++)
      {
            tat[i] = ct[i]-at[i];
            wt[i] = tat[i] - bt[i];
            atat+=tat[i];
            awt+=wt[i];
      }

      atat/=n;
      awt/=n;
}

int main()
{
      int *p,*at,*bt,*tat,*ct,*wt,pos,i,j,min=1000,n;
      printf("Enter the number of processes: \n");
      scanf("%d",&n);
      p = (int*)malloc(n*sizeof(int));
      at = (int*)malloc(n*sizeof(int));
      bt = (int*)malloc(n*sizeof(int));
      tat = (int*)malloc(n*sizeof(int));
      ct = (int*)malloc(n*sizeof(int));
      wt = (int*)malloc(n*sizeof(int));

      
      printf("Enter %d process\n",n);
      for(i=0;i<n;i++)
      scanf("%d",&p[i]);
      printf("Enter arrival time\n");
      for(i=0;i<n;i++)
      scanf("%d",&at[i]);
      printf("Enter burst time\n");
      for(i=0;i<n;i++)
      scanf("%d",&bt[i]);

      sortAt(p,at,bt,n);
      ct[0] = at[0]+bt[0];

      for(i=1;i<n;i++)
      {
            for(j=i;j<n;j++)
            {
                  
                  if(at[j]<=ct[i-1])
                  {
                        if(bt[j]<min)
                        {
                              min = bt[j];
                              pos = j;
                        }
                  }
            }
            swap(&p[i],&p[pos]);
            swap(&at[i],&at[pos]);
            swap(&bt[i],&bt[pos]);
            min = 1000;
            ct[i] = ct[i-1] + bt[i];
      }
      calc(ct,at,bt,tat,wt,n);

      printf("\nP\tAT\tBT\tCT\tTAT\tWT");
      for(i=0;i<n;i++)
      {
            printf("\nP%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
      }

      printf("\nAverage Turn Around Time: %f",atat);
      printf("\nAverage Waiting Time: %f",awt);
      return 0;
}