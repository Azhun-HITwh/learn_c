//
//  stack.h
//  learnc
//
//  Created by Azhun Zhu on 2022/1/8.
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
