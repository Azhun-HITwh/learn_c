//
//  test.h
//  learnc
//
//  Created by Azhun Zhu on 2022/9/14.
//

#ifndef test_h
#define test_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

typedef void (*pf_callback)(int a);

typedef struct Compute_ST
{
    int index;
    pf_callback function;
}Compute_ST;

int Register_Callback_Fun(Compute_ST *registed_fun);

void mgmtb_fun(int num);
#endif /* test_h */
