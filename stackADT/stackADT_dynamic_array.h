//
//  stackADT_dynamic_array.h
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/9.
//

#ifndef stackADT_dynamic_array_h
#define stackADT_dynamic_array_h

#include <stdio.h>
#include <stdbool.h>

typedef int Item;
typedef struct stack_type Stack;

Stack *create(int);
void destory(Stack *s);
void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s, Item i);
int pop(Stack *s);

#endif /* stackADT_dynamic_array_h */
