#include<stdio.h>

int main()
{
      int p,r,i,j,cnt=0;
      int alloc[10][10],max[10][10],need[10][10], safe[10], available[10], done[10];
      int terminate = 0;
      printf("Enter the number of proccesses and resources: ");
      scanf("%d %d",&p,&r);
      printf("Enter the allocation matrix of all processes in a %d x %d matrix\n",p,r);
      for(i=0;i<p;i++)
      {
            for(j=0;j<r;j++)
            {
                  scanf("%d",alloc[i][j]);
            }
            printf("\n");
      }

      printf("Enter the maximum resources matric of all processes in a %d x %d matrix\n",p,r);
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
      done[i] = 0; //keeping track of what proccess are done

      while(cnt<p) //iterating till all the process are completed
      {
            for(i=0;i<p;i++) //iterating through all processes
            {
                  if(done[i]==0) //that particular process isn't completed 
                  {
                        for(j=0;j<r;j++)  //iterating through the resources
                        {
                              if(need[i][j]>available[j]) //wont check further if this statement is true, it will come out of the loop
                                    break;
                        }

                        if(j==r) //process can be allocated since j==r
                        {
                              safe[cnt] = i; //i indicated process number
                              done[i] = 1; //updating the completion of ith process

                              for(j=0;j<r;j++)
                              {
                                    available[j]+=alloc[i][j]; //releasing the allocated resources
                              }

                              cnt++; //incrementing counter since process is done
                              terminate=0;
                        }
                        else
                        {
                              terminate++;
                        }
                  }
            }

            if(terminate==(p-1)) //this means all proccesses except one has been checked and none can be executed
            {
                  printf("Safe sequence doesnt exist");
                  break;
            }
      }

      if(terminate!=(p-1))
      {
            printf("The available resources after completetion are: \n");
            for(i=0;i<r;i++)
            {
                  printf("%d\t",available[i]);
            }

            printf("\nThe safe sequence is: \n");
            for(i=0;i<p;i++)
            {
                  printf("P%d->\t",safe[i]);
            }
      }

      return 0;

}