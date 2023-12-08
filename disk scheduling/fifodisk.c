//implementing fifo disk scheduling

#include<stdio.h>
#include<stdlib.h>

int main()
{
      int rq[100],i,n,totalheadmmt = 0,initial;
      printf("Enter the number of requests:\n");
      scanf("%d",&n);
      printf("Enter the requests sequence:\n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&rq[i]);
      }
      printf("Enter the initial head position:\n");
      scanf("%d",&initial);
      for(i=0;i<n;i++)
      {
            totalheadmmt = totalheadmmt + abs(rq[i] - initial);
            printf("Move head from %d to %d\n",initial,rq[i]);
            initial = rq[i];
      }
      printf("Total head moment: %d \n",totalheadmmt);
      return 0;
}