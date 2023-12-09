#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
      int queue[100],queue2[100],n,head,seek=0,temp,j,i;
      printf("Enter the number of request: \n");
      scanf("%d",&n);
      printf("Enter the request sequence: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&queue[i]);
      }
      printf("Enter the head position: \n");
      scanf("%d",&head);

      //finding the distance of each element from head and storing it in array
      for(i=0;i<n;i++)
      {
            queue2[i] = abs(head-queue[i]);
      }

      for(i=0;i<n;i++)
      {
            for(j=i+1;j<n;j++)
            {
                  if(queue2[i]>queue2[j])
                  {
                        //swapping in array 2
                        temp = queue2[i];
                        queue2[i] = queue2[j];
                        queue2[j] = temp;

                        //swapping the corresponding elements in the first array
                        temp = queue[i];
                        queue[i] = queue[j];
                        queue[j] = temp;
                  }
            }
      }

      for(i=0;i<n;i++)
      {
            seek+=abs(head-queue[i]);
            printf("Move head from %d to %d\n",head,queue[i]);
            head = queue[i];
      }

      printf("The seek time is: %d",seek);
      return 0;
}