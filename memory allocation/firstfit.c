#include<stdio.h>
void first_fit(int block[],int process[],int bc, int pc)
{
      int allocation[pc];
      int i,j;
      for(i=0;i<pc;i++)
      {
            allocation[i]=-1;
            for(j=0;j<bc;j++)
            {
                  if(block[j]>=process[i])
                  {
                        allocation[i] = j;
                        block[j] -= process[i];
                        break;
                  }
            }
      }

      printf("Process No. Process Size\tFragment\tBlock No.\n");
      for(i=0;i<pc;i++)
      {
            printf("%d\t\t%d\t\t%d\t\t",i+1,process[i],block[i]);
            if(allocation[i]!=-1)
            {
                  printf("%d\n",allocation[i]+1);
            }
            else
            {
                  printf("Not allocated\n");
            }
      }
}

int main()
{
      int block[10],process[10],bc,pc,i;
      printf("Enter the number of blocks:");
      scanf("%d",&bc);
      printf("Enter the number of processes:");
      scanf("%d",&pc);
      printf("Enter the size of each block:");
      for(i=0;i<bc;i++)
      {
            printf("\nBlock %d: ",(i+1));
            scanf("%d",&block[i]);
      }
      printf("Enter the size of each process:");
      for(i=0;i<pc;i++)
      {
            printf("\nProcess %d: ",(i+1));
            scanf("%d",&process[i]);
      }
      first_fit(block,process,bc,pc);
}