#include<stdio.h>

void worstfit_algo(int block[],int process[],int bc,int pc);

int main()
{
      int block[10],process[10],bc,pc,i;
      printf("Enter the number of blocks: \n");
      scanf("%d",&bc);
      printf("Enter the number of processes: \n");
      scanf("%d",&pc);
      printf("Enter the size of %d blocks: \n",bc);
      for(i=0;i<bc;i++)
      {
            printf("Block %d: \n",(i+1));
            scanf("%d",&block[i]);
      }
      printf("Enter the size of %d processes: \n",pc);
      for(i=0;i<pc;i++)
      {
            printf("Process %d: \n",(i+1));
            scanf("%d",&process[i]);
      }

      worstfit_algo(block,process,bc,pc);
}

void worstfit_algo(int block[],int process[],int bc,int pc)
{
      int allocation[pc];
      int i,j,wfi;
      for(i=0;i<pc;i++)
      {
            wfi = -1;
            for(j=0;j<bc;j++)
            {
                  if(block[j]>process[i])
                  {
                        if(wfi==-1 || block[wfi]<block[j]) //basically finding the max block size for that process
                        {
                              wfi = j;
                        }
                  }
            }
            if(wfi!=-1)
            {
                  allocation[i] = wfi;
                  block[wfi] -= process[i];
            }
            else
            {
                  allocation[i] = -1;
            }
      }

      printf("Process No\tProcess Size\tFragment\tBlock No\n");
      for(i=0;i<pc;i++)
      {
            printf("%d\t\t%d\t\t%d\t\t",(i+1),process[i],block[i]);
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
