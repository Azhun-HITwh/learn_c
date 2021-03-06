//
//  main.c
//  stack
//
//  Created by Azhun Zhu on 2021/12/26.
//

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node{
    int data;
    struct node* next;
}node;

static node* top = NULL;

static void terminate(char* message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void){
    while (!is_empty()) {
        pop();
    }
}

bool is_empty(void) {
    return top == NULL;
}

bool is_full(void) {
    return false;
}

void push(int i){
    
    node* new_node = (node*)malloc(sizeof(node));
    
    if (new_node == NULL) {
        terminate("Error in push: stack is full.\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

int pop(void){
    
    if (is_empty()) {
        terminate("Error in pop: stack is empty.\n");
    }
    
    int data = top->data;
    
    node* del = top;
    top = top->next;
    free(del);
    
    return data;
}

int main(int argc, const char * argv[]) {
    push(10);
    int pop_value;
    pop_value = pop();
    printf("%d\n", pop_value);
    return 0;
}
