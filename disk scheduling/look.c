#include<stdio.h>
#include<stdlib.h>

int main()
{
      int rq[100],i,j,inital,seek=0,n;
      printf("Enter the number of requests:\n");
      scanf("%d",&n);
      printf("Enter the requests:\n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&rq[i]);
      }
      printf("Enter the initial head position:\n");
      scanf("%d",&inital);

      for(i=0;i<n;i++)
      {
            for(j=0;j<n-i-1;j++)
            {
                  if(rq[j]>rq[j+1])
                  {
                        int temp;
                        temp=rq[j];
                        rq[j]=rq[j+1];
                        rq[j+1]=temp;
                  }
            }
      }

      int index;
      //for loop to find the largest element after head
      for(i=0;i<n;i++)
      {
            if(inital<rq[i])
            {
                  index = i;
                  break;
            }
      }

      for(i=index;i<n;i++)
      {
            seek+=abs(rq[i]-inital);
            printf("Move head from %d to %d\n",inital,rq[i]);
            inital=rq[i];
      }

      for(i=index-1;i>=0;i--)
      {
             seek+=abs(rq[i]-inital);
            printf("Move head from %d to %d\n",inital,rq[i]);
             inital=rq[i];
            
      }

      printf("Total seek time: %d \n",seek);
      return 0;
}