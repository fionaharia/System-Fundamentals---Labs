#include<stdio.h>
#include<stdlib.h>

int mutex = 1;   //dec when producing, incre when consuming
int full = 0;
int empty = 10;  //number of emplty slots in the buffer
int data = 0;    //data is produced

void producer()
{
      --mutex;
      ++full;
      --empty;
      data++;

      printf("\nProducer produces item number: %d\n",data);

      ++mutex;
}

void consumer()
{
      --mutex;
      --full;
      ++empty;
      printf("\nConsumer consumes item number: %d\n",data);
      data--;
      ++mutex;
}

int main()
{
      int ch,i;
      printf("Enter 1 for Producer\nEnter 2 for consumer\nEnter 3 for exit\n");
      for(i=1;i>0;i++)
      {
            printf("Enter your choice: \n");
            scanf("%d",&ch);

            switch (ch)
            {
            case 1:
                  if((mutex==1)&&(empty!=0))
                  {
                        producer();
                  }
                  else
                        printf("buffer is full. new data cant be produced");
                  break;
            
            case 2:
                  if((mutex==1)&&(full!=0))
                  {
                        consumer();
                  }
                  else
                        printf("buffer is empty. data can't be confused");
                  break;
            
            case 3:
                  exit(0);
                  break;
            
            default:
                  printf("wrong choice");
            }
      }
}