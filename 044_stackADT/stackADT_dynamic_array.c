//
//  stackADT_dynamic_array.c
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/9.
//

#include "stackADT_dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_type {
    int top;
    int size;
    Item contents[];
}Stack;


static void terminate(char* message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}


Stack *create(int size) {

    Stack *s = (Stack *)malloc(sizeof(Stack) + sizeof(Item) * size);
    if (s == NULL) {
        terminate("Error in create: stack could not be created.\n");
        exit(EXIT_FAILURE);
    }
    s->top = 0;
    s->size = size;

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
    return s->top == s->size;
}

void push(Stack *s, Item i) {

    if (is_full(s)) {
        terminate("Error in push: stack is full.\n");
        exit(EXIT_FAILURE);
    }

    s->contents[s->top++] = i;
}

Item pop(Stack *s) {

    if (is_empty(s)) {
        terminate("Error in pop: stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    return s->contents[--s->top];
}
