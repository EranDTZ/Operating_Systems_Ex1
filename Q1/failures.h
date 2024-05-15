#ifndef FAILURES_H
#define FAILURES_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

//Struct build;
typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

void stackOverflow(Stack *s);
void Division_byZero(int num);
void Undefined_Value();

#endif /* FAILURES_H */
