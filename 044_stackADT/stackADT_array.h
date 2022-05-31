//
//  stackADT_array.h
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/8.
//

#ifndef stackADT_array_h
#define stackADT_array_h

#include <stdio.h>
#include <stdbool.h>

typedef struct stack_type Stack;

Stack *create(void);
void destory(Stack *s);
void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);


#endif /* stackADT_array_h */
