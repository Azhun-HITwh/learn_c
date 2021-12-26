//
//  stack.h
//  stack
//
//  Created by Azhun Zhu on 2021/12/26.
//

#ifndef stack_h
#define stack_h

#include<stdbool.h> //C99 only

void make_empty();
bool is_empty();
bool is_full();
void push(int i);
int pop();

#endif /* stack_h */
