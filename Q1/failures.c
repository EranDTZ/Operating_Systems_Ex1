#include "failures.h"

void stackOverflow(Stack *s) {
    s->top++; //Add value to stack;
    stackOverflow(s); //Recursive call to itself;
}

void Division_byZero(int num){
    int zero = 0;
    if (num != 0) {
        num = num/zero;
    } 
    else printf("ERROR : number is not greater than 0\n"); 
}


void Undefined_Value() {
    int *ptr = NULL; //Pointer to undefined address;
    printf("Trying to access Value at undefined memory address: %d\n", *ptr); //Attempt to read undefined address;
}
