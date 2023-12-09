#include<stdio.h>

void optimal_algo(int pageref[],int frames,int pages);

int main()
{
      int i,frames,pages;
      printf("Enter the number of frames: \n");
      scanf("%d",&frames);
      printf("Enter the number of pages: \n");
      scanf("%d",&pages);
      int pageref[pages];
      printf("Enter %d page references: \n",pages);
      for(i=0;i<pages;i++)
      {
            scanf("%d",&pageref[i]);
      }

      optimal_algo(pageref,frames,pages);
      return 0;
}

void optimal_algo(int pageref[],int frames,int pages)
{
      int i,j,k,hits=0,miss=0,index=-1,full=0;
      int framearr[frames];
      for(i=0;i<frames;i++)
            framearr[i] = -1;
      
      for(i=0;i<pages;i++)
      {
            int symbol = pageref[i];
            int flag = 0;
            for(j=0;j<frames;j++)
            {
                  if(symbol==framearr[j])
                  {
                        flag=1;
                        break;
                  }
            }

            if(flag==1) //page hit
            {
                  printf("\nSymbol: %d Frame: ",symbol);
                  for(j=0;j<frames;j++)
                        printf("%d ",framearr[j]);
                  hits++;
            }
            else //page miss
            {
                  if(full==0) //frames are empty
                  {
                        index =(index+1)%frames;
                        framearr[index] = symbol;
                        miss++;
                        printf("\nSymbol: %d Frame: ",symbol);
                        for(j=0;j<frames;j++)
                              printf("%d ",framearr[j]);
                        
                        if(i==(frames-1))  //to check if frames are full
                              full=1;
                  }

                  else //frames are full
                  {
                        int pos=-1,index=-1;
                        for(j=0;j<frames;j++)
                        {
                              int found = 0;
                              for(k=(i+1);k<pages;k++)
                              {
                                    if(framearr[j]==pageref[k])
                                    {
                                          found = 1;
                                          if(pos<k)
                                          {
                                                pos = k; //position of the page 
                                                index = j; //index of the frame to be replaced
                                          }
                                          break;
                                    }
                              }

                              if(found==0)
                              {
                                    pos = pages;
                                    index = j;
                              }
                        }

                        miss++;
                        framearr[index] = symbol;
                        printf("\nSymbol: %d Frame: ",symbol);
                        for(j=0;j<frames;j++)
                              printf("%d ",framearr[j]);
                  }
            }
      }

      printf("\nPage Hits: %d",hits);
      printf("\nPage Misses: %d",miss);      
}