#include<stdio.h>
void best_fit(int block[],int process[],int bc, int pc)
{
      int allocation[pc];
      int i,j,bst;
      for(i=0;i<pc;i++)
      {
            bst=-1;
            for(j=0;j<bc;j++)
            {
                  if(block[j]>=process[i])
                  {
                        if(bst==-1 || (block[bst]>block[j]))
                        {
                              bst = j;
                        }
                  }
            }
            if(bst!=-1)
            {
                  allocation[i] = bst;
                  block[bst] -= process[i];
            }
      }

      printf("Process No.   Process Size\t Fragment\tBlock No.\n");
      for(i=0;i<pc;i++)
      {
            printf("%d\t\t%d\t\t%d\t\t",i+1,process[i],block[i]);
            if(allocation[i] != (-1))
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
      best_fit(block,process,bc,pc);
}