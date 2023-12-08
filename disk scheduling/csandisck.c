#include<stdio.h>
#include<stdlib.h>

int main()
{
      int queue[100],n,head,i,j,k,seek=0,maxrange,temp,temp1,temp2,queue1[100],queue2[100];

      printf("Enter the maximum rannge of the disk: \n");
      scanf("%d",&maxrange);

      printf("Enter the number of queue requests: \n");
      scanf("%d",&n);

      printf("Enter the initial head position: \n");
      scanf("%d",&head);

      printf("Enter the request queue: \n");
      for(i=1;i<=n;i++)
      {
            scanf("%d",&temp);
            if(temp>head)
            {
                  queue1[temp1] = temp;
                  temp1++;
            }
            else
            {
                  queue2[temp2] = temp;
                  temp2++;
            }
      }
      //sorting second half of the array in ascending order
      for(i=0;i<temp1-1;i++)
      {
            for(j=i+1;j<temp1;j++)
            {
                  if(queue1[i]>queue1[j])
                  {
                        temp = queue1[i];
                        queue1[i] = queue1[j];
                        queue1[j] = temp;
                  }
            }
      }

      //sorting first half of the array in descending order
       for(i=0;i<temp2-1;i++)
      {
            for(j=i+1;j<temp2;j++)
            {
                  if(queue2[i]>queue2[j])
                  {
                        temp = queue2[i];
                        queue2[i] = queue2[j];
                        queue2[j] = temp;
                  }
            }
      }

      for(i=1,j=0;j<temp1;i++,j++)
      {
            queue[i] = queue1[j];
      }
      queue[i] = maxrange;
      queue[i+1] = 0;

      for(i=temp1+3,j=0;j<temp2;i++,j++)
      {
            queue[i] = queue2[j];
      }

      queue[0] = head;

      for(j=0;j<=n+1;j++)
      {
            seek += abs(queue[j+1]-queue[j]);
            printf("Move head from %d to %d\n",queue[j],queue[j+1]);
      }

      printf("Seek time: %d",seek);
      return 0;
}