# include <stdio.h>
#include <stdlib.h>
# include "failures.h"
#include "poisson.h"

int main(){
    int flag = 0;
    printf("for - stackOverflow enter 1\nfor - Division_byZero enter 2\nfor - Undefined_Value enter 3\n");
    printf("Please enter me a number to select a func:\n");
    if (scanf("%d", &flag))
    {
        if (flag == 1)
        {
            printf("stack Overflow will by preporm now...\n");

            Stack s;
            s.top = -1;
            //function activates infinite recursion!;
            stackOverflow(&s);
        }

        if (flag == 2)
        {
            int num;
            printf("Please enter me a number greater than 0:\n");
            if (scanf("%d",&num))
            {
                printf("Division_byZero func will by preporm now...\n");
                Division_byZero(num); 
            }
            else printf("ERROR : scanf bed syntx\n"); 
        }

        if (flag == 3)
        {
            printf("Undefined_Value func will by preporm now...\n");
            Undefined_Value();
        }
    }
    else printf("ERROR : scanf bed syntx\n");

    return 0;
    
}