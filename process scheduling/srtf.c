#include<stdio.h>
#include<stdlib.h>

struct process
{
     int process_id;
     int arr_time;
     int bur_time;
     int wait_time;
     int turn_time;
     int complete_time;
     int remain_time;
};

int main()
{
      int i,j,n;
      int bt=0,k=1,tat=0,sum=0,min;
      printf("Enter the number of process: \n");
      scanf("%d",&n);
      
      struct process proc[n],temp;

      for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter arrival time for process%d: ",i+1);
		scanf("%d",&proc[i].arr_time);
		printf("Enter burst time for process%d: ",i+1);
		scanf("%d",&proc[i].bur_time);
		proc[i].remain_time = proc[i].bur_time;
		proc[i].process_id = i+1;
	}

      int quantum_time,flag=0;
      printf("Enter time quantum: \n");
      scanf("%d",&quantum_time);
      int proc_remaining = n;

      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                  if(proc[i].arr_time<proc[j].arr_time)
                  {
                        temp = proc[j];
                        proc[j] = proc[i];
                        proc[i] = temp;
                  }
            }
      }

      int wt_total = 0;
      int tat_total = 0;
      int exec_total = 0;

      i=0;

      while(proc_remaining!=0)
      {
            //process will complete in this iteration itself
            if(proc[i].remain_time<=quantum_time && proc[i].remain_time>0)
            {
                  exec_total+=proc[i].remain_time;
                  proc[i].remain_time = 0; //process completed
                  flag = 1; 
            }
            else if(proc[i].remain_time>0)
            {
                  proc[i].remain_time -= quantum_time;
                  exec_total += quantum_time;
            }

            //indicating process is completed
            if(flag==1 && proc[i].remain_time==0)
            {
                  proc[i].turn_time = exec_total - proc[i].arr_time;
                  proc[i].wait_time = proc[i].turn_time - proc[i].bur_time;

                  wt_total+=proc[i].wait_time;
                  tat_total+=proc[i].turn_time;

                  flag=0; //reseting flag value for next iteration
                  proc_remaining--; //decrementing process counter
            }

            //this means we are at the last process, we need to go back to the first process
            if(i==n-1)
            {
                  i=0;
            }
            //the next process has arrived
            else if(proc[i+1].arr_time<=exec_total)
            {
                  i++;
            }
            //process hasnt arrived, so we go back to the first process
            else
            {
                  i=0;
            }
      }

      printf("Process\tAT\tBT\tTAT\tWT\n");
      for(i=0;i<n;i++)
      {
            printf("%d\t%d\t%d\t%d\t%d\n",proc[i].process_id,proc[i].arr_time,proc[i].bur_time,proc[i].turn_time,proc[i].wait_time);
      }

      printf("Average waiting time: %f\n",(float)wt_total/n);
       printf("Average Turn around time: %f\n",(float)tat_total/n);

}