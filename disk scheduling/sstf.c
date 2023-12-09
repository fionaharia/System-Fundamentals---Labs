#include<stdio.h>
#include<stdlib.h>

int main()
{
      int rq[100],i,n,headmoment=0,initial,cnt=0;
      printf("Enter the number of requests: \n");
      scanf("%d",&n);
      printf("Enter the requests: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&rq[i]);
      }
      printf("Enter initial head position: \n");
      scanf("%d",&initial);

      while(cnt!=n)
      {
            int d,min=1000,index;
            for(i=0;i<n;i++)
            {
                  d = abs(rq[i]-initial);
                  if(min>d)
                  {
                        min = d;
                        index = i;
                  }
            }
            headmoment+=min;
            printf("Move head from %d to %d\n",initial,rq[index]);
            initial = rq[index];
            rq[index] = 1000;
            cnt++;
      }

      printf("Seek: %d\n",headmoment);
      return 0;
}