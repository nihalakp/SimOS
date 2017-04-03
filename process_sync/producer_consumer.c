#include <stdio.h>
#include <stdlib.h>

int temp = 0, overflow = 0, lock = 1, underflow = 8;
int consumed(int counter)
{
return (--counter);
}
int produced(int counter)
{
return(++counter);
}
void producer()
{
     lock = consumed(lock);
     overflow = produced(overflow);
     underflow = consumed(underflow);
     temp++;
     printf("\nProducer:\t Element %d\n", temp);
     lock = produced(lock);
}
void consumer()
{
     lock = consumed(lock);
     overflow = consumed(overflow);
     underflow = produced(underflow);
     printf("\nConsumer:\t Element %d\n", temp);
     temp--;
     lock = produced(lock);
}
int main()
{
int choice;
     printf("\n1.Producer\t");
printf("2. Consumer\t");
printf("3. Quit\t");
     while(1)
     {
         printf("\nEnter your choice:\t");
         scanf("%d", &choice);
switch(choice)
         {
             case 1: if((lock == 1) && (underflow != 0))
                         {
                           producer();
                           printf("Items now:%d\n",temp);
                         }
                     else
                         {
                          printf("No space left to produce!\n");
                         }
                     break;
             case 2: if((lock == 1) && (overflow != 0))
                         {
                          consumer();
                          printf("Items now:%d\n",temp);
                         }
                     else
                         {
                          printf("No items left to consume!\n");
                         }
                     break;
             case 3: exit(0);
                     break;
         }
     }
     return 0;
}
