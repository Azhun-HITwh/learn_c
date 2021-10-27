//
//  main.c
//  pointer
//
//  Created by Azhun Zhu on 2021/10/27.
//

#include <stdio.h>

const int MAX = 4;

int main()
{
    const char *names[] = {
                           "Zara Ali",
                           "Hina Ali",
                           "Nuha Ali",
                           "Sara Ali",
    };
    int i = 0;
    
    for (i = 0; i < MAX; i++)
    {
        printf("Value of names[%d] = %s\n", i, names[i] );
    }
    return 0;
}
