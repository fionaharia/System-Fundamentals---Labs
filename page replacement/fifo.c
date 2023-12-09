#include<stdio.h>
void fifo_algo(int pageref[],int frames,int pages);
int main()
{
      int frames,pages,i;
      printf("Enter the number of frames: \n");
      scanf("%d",&frames);
      printf("Enter the number of pages: \n");
      scanf("%d",&pages);
      int pageref[pages];
      printf("Enter %d page reference elements: \n",pages);
      for(i=0;i<pages;i++)
            scanf("%d",&pageref[i]);
      
      fifo_algo(pageref,frames,pages);
      return 0;
}

void fifo_algo(int pageref[],int frames,int pages)
{
      int i,j;
      int framearr[frames]; //creating array for block storage
      for(i=0;i<frames;i++)
            framearr[i] = -1;
      
      int index=-1,miss=0,hits=0;

      for(i=0;i<pages;i++)    //traversing through each page
      {
            int symbol = pageref[i]; //each page
            int flag = 0;
            for(j=0;j<frames;j++)   //traversing through each frame
            {
                  if(symbol==framearr[j])
                  {
                        flag=1;
                        break;
                  }
            }

            if(flag==1)
            {
                  printf("\nSymbol: %d Frame: ",symbol);
                  for(j=0;j<frames;j++)
                  {
                        printf("%d ",framearr[j]);
                  }
                  hits++;
            }
            else
            {
                  index = (index+1)%frames;
                  framearr[index] = symbol;
                  miss++;
                  printf("\nSymbol: %d Frame: ",symbol);
                  for(j=0;j<frames;j++)
                  {
                        printf("%d ",framearr[j]);
                  }
            }
      }

      printf("\nPage Hits: %d",hits);
      printf("\nPage Misses: %d",miss);
}