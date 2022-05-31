//
//  stackADT_linkedlist.h
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/9.
//

#ifndef stackADT_linkedlist_h
#define stackADT_linkedlist_h

#include <stdio.h>

typedef int Item;
typedef struct stack_type Stack;

Stack *create(void);
void destory(Stack *s);
void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s, Item i);
Item pop(Stack *s);

#endif /* stackADT_linkedlist_h */
