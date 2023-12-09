#include<stdio.h>
void lru_algo(int pageref[],int frames,int pages);
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
      
      lru_algo(pageref,frames,pages);
      return 0;
}

void lru_algo(int pageref[],int frames,int pages)
{
      int framearr[frames];
      int i,j;
      for(i=0;i<frames;i++)
      {
            framearr[i] = -1;

      }
      int index=-1,miss=0,hits=0;

      for(i=0;i<pages;i++)
      {
            int flag=0;
            int full = 0;
            int symbol = pageref[i];
            for(j=0;j<frames;j++)
            {
                  if(symbol==framearr[j])
                  {
                        flag = 1;
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
                  if(full==0)
                  {
                        index=(index+1)%frames;
                        framearr[index]=symbol;
                        miss++;
                        for(j=0;j<frames;j++)
                        {
                              printf("%d ",framearr[j]);
                        }
                  }

                  else
                  {
                        int pos=999;
                        int index=-1;
                        for(j=0;j<frames;j++)
                        {
                              for(int k=0;k<pages;k++)
                              {
                                    if(framearr[j]==pageref[k])
                                    {
                                          if(pos>k)
                                          {
                                                pos = k;
                                                index = j;
                                                break;
                                          }
                                    }
                              }
                        }
                        framearr[index] = symbol;
                        miss++;
                        printf("\nSymbol: %d Frame: ",symbol);
                        for(j=0;j<frames;j++)
                        {
                              printf("%d ",framearr[j]);
                        }
                  }
            }
      }
      printf("\nPage Hits: %d",hits);
      printf("\nPage Misses: %d",miss);  

}



