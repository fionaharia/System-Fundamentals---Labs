#include<stdio.h>

int main()
{
      int p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,n,temp=0;
      float awt = 0, atat = 0;

      printf("Enter the number of process: \n");
      scanf("%d",&n);
      printf("Enter %d process\n",n);
      for(i=0;i<n;i++)
      scanf("%d",&p[i]);
      printf("Enter arrival time\n");
      for(i=0;i<n;i++)
      scanf("%d",&at[i]);
      printf("Enter burst time\n");
      for(i=0;i<n;i++)
      scanf("%d",&bt[i]);

      //sorting bt,at according to at

      for(i=0;i<n;i++)
      {
            for(j=0;j<(n-i);j++)
            {
                  if(at[j]>at[j+1])
                  {
                        //process
                        temp = p[j+1];
                        p[j+1] = p[j];
                        p[j] = temp;

                        //arrival time
                        temp = at[j+1];
                        at[j+1] = at[j];
                        at[j] = temp;

                        //burst time
                        temp = bt[j+1];
                        bt[j+1] = bt[j];
                        bt[j] = temp;
                  }
            }
      }

      //first ct
      ct[0] = at[0]+bt[0];

      //calc remaining ct
      for(i=1;i<n;i++)
      {
            //when the process is idle between i and i+1
            temp = 0;
            if(ct[i-1]<at[i])
            {
                  temp = at[i] - ct[i-1];
            }
            ct[i] = ct[i-1] + bt[i] + temp;
      }

      //calc tat and wt
      for(i=0;i<n;i++)
      {
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            atat+=tat[i];
            awt+=wt[i];
      }

      atat/=n;
      awt/=n;

      printf("\nP\tAT\tBT\tCT\tTAT\tWT");
      for(i=0;i<n;i++)
      {
            printf("\nP%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
      }

      printf("\nAverage Turn Around Time: %f",atat);
      printf("\nAverage Waiting Time: %f",awt);
      return 0;

}