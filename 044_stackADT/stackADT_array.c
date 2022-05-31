//
//  stackADT_array.c
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT_array.h"

#define STACK_SIZE 100

typedef struct stack_type {
    int contents[STACK_SIZE];
    int top;
}Stack;



static void terminate(char* message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack *create() {

    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        terminate("Error in create: stack could not be created.\n");
        exit(EXIT_FAILURE);
    }
    s->top = 0;

    return s;
}


void destory(Stack *s) {

    free(s);
}


void make_empty(Stack *s) {

    s->top = 0;
}

bool is_empty(Stack *s) {
    return s->top == 0;
}

bool is_full(Stack *s) {
    return s->top == STACK_SIZE;
}

void push(Stack *s, int i) {

    if (is_full(s)) {
        terminate("Error in push: stack is full.\n");
        exit(EXIT_FAILURE);
    }

    s->contents[s->top++] = i;
}

int pop(Stack *s) {

    if (is_empty(s)) {
        terminate("Error in pop: stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    return s->contents[--s->top];
}
