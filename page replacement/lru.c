#include<stdio.h>
#include<limits.h>


int checkHit(int incomingPage,int queue[],int occupied);
void printFrame(int queue[],int occupied);

int checkHit(int incomingPage,int queue[],int occupied)
{
      for(int i=0;i<occupied;i++)
      {
            if(incomingPage==queue[i])
            {
                  return 1;
            }
      }
      return 0;
}

void printFrame(int queue[],int occupied)
{
      for(int i=0;i<occupied;i++)
      {
            printf("%d\t\t",queue[i]);
      }
}

int main()
{
      int frames, n;
      printf("Enter the number of frames: ");
      scanf("%d", &frames);
      printf("Enter the number of pages: ");
      scanf("%d", &n);

      int incomingStream[n];
      printf("Enter the page sequence:\n");
      for (int i = 0; i < n; i++)
      {
            printf("Page %d: ", i + 1);
            scanf("%d", &incomingStream[i]);
      }

      int queue[frames];
      int distance[frames];
      int occupied = 0;
      int miss = 0;
      int hit=0;

      printf("Pages\n");

      for(int i=0;i<n;i++)
      {
            printf("%d\t\t",incomingStream[i]);
            if(checkHit(incomingStream[i],queue,occupied))
            {
                  printFrame(queue,occupied);
                  hit++;
            }

            else if(occupied<frames)
            {
                  queue[occupied] = incomingStream[i];
                  miss++;
                  occupied++;
                  printFrame(queue,occupied);
            }

            else
            {
                  int max = INT_MIN;
                  int index;

                  for(int j=0;j<frames;j++)
                  {
                        distance[j] = 0;
                        for(int k=i-1;k>=0;k--)
                        {
                              ++distance[j];
                              if(incomingStream[k]==queue[j])
                                    break;
                        }
                        if(distance[j]>max)
                        {
                              max = distance[j];
                              index = j;
                        }
                  }

                  queue[index] = incomingStream[i];
                  printFrame(queue,occupied);
                  miss++;
            }
            printf("\n");

      }

      printf("Page Hits: %d \n",hit);
      printf("Page Miss: %d \n",miss);
      return 0;
}