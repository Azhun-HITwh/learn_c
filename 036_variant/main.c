//
//  main.c
//  variant
//
//  Created by Azhun Zhu on 2021/10/19.
//

#include <stdio.h>

int x=1;
int y=2;
int addtwonum(void);
int main(void) {
    int result;
    result = addtwonum();
    printf("result: %d\n", result);
    return 0;
}
