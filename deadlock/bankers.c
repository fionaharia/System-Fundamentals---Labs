#include<stdio.h>

int main()
{
      int p,r,i,j,cnt=0;
      int alloc[10][10],max[10][10],need[10][10], safe[10], available[10], done[10];
      int terminate = 0;
      printf("Enter the number of proccesses and resources:  ");
      scanf("%d %d",&p,&r);
      printf("Enter the allocation matrix of all processes in a %d x %d matrix",p,r);
      for(i=0;i<p;i++)
      {
            for(j=0;j<r;j++)
            {
                  scanf("%d",alloc[i][j]);
            }
      }

      printf("Enter the maximum resources matric of all processes in a %d x %d matrix",p,r);
      for(i=0;i<p;i++)
      {
            for(j=0;j<r;j++)
            {
                  scanf("%d",max[i][j]);
            }
      }

      printf("Enter the available resouces: ");
      for(i=0;i<r;i++)
      scanf("%d",&available[i]);

      printf("\nThe need resources matrix is: \n");
      for(i=0;i<p;i++)
      {
            for(j=0;j<r;j++)
            {
                  need[i][j] = max[i][j] - alloc[i][j];
                  printf("%d  ",need[i][j]);
            }
            printf("\n");
      }

      for(i=0;i<p;i++)
      done[i] = 0;

      while(cnt<p)
      {
            for(i=0;i<p;i++)
            {
                  if(done[i]==0)
                  {
                        for(j=0;j<r;j++)
                        {
                              if(need[i][j] > available[j])
                              break;
                        }

                        //it confirms that it has iterated through all of the resources for that process
                        if(j==r)
                        {
                              safe[cnt] = i;
                              done[i] = 1;
                              for(j=0;j<r;j++)
                              {
                                    available[j]+=alloc[i][j];
                              }

                              cnt++;
                              terminate = 0;
                        }
                        else
                              terminate++;
                  }
            }
      }

}