//
//  main.c
//  bool_type
//
//  Created by Azhun Zhu on 2021/10/20.
//

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n = 10;
    int sum = 1;
    bool flag = false;
    
    int num = n;
    while (!flag) {
        sum = sum * (num--);
        if (num==1)
        {
            flag = true;
        }
    }
    printf("%d的叠乘值为 %d\n", n, sum);
    return 0;
}

