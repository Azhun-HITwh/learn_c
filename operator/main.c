//
//  main.c
//  operator
//
//  Created by Azhun Zhu on 2021/10/20.
//

#include <stdio.h>

int func1(int);

int main(void)
{
    unsigned int a = 10;
    unsigned int b = 20;
    printf("a:%d, b:%d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a:%d, b:%d\n", a, b);
    a^=b^=a^=b;
    printf("a:%d, b:%d\n", a, b);
    if (func1(20))
    {
        printf("20是2的整数次幂\n");
    }
    else
    {
        printf("20不是2的整数次幂\n");
    }
}

int func1(int num)
{
    return ((num > 0) && ((num & (num - 1)) == 0));
}
