//
//  stackADT_linkedlist.c
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/9.
//

#include <stdlib.h>
#include <stdbool.h>
#include "stackADT_linkedlist.h"

typedef struct node {
    Item content;
    struct node *next;
}node;

typedef struct stack_type {
    node* top;
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
    s->top = NULL;

    return s;
}

void destory(Stack *s) {

    make_empty(s);
    free(s);
}

void make_empty(Stack *s) {
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack *s) {
    return s->top == NULL;
}

bool is_full(Stack *s) {
    return false;
}

void push(Stack *s, Item i){
    
    node *new_node = (node *)malloc(sizeof(node));
    
    new_node->content = i;
    new_node->next = s->top;
    s->top = new_node;

}

Item pop(Stack *s){
    
    if (is_empty(s)) {
        terminate("Error in pop: stack is empty.\n");
    }
    
    Item data = s->top->content;
    
    node *del = (node *)malloc(sizeof(node));
    del = s->top;
    s->top = s->top->next;
    free(del);
    
    return data;
}
