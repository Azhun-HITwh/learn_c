//
//  main.c
//  pointer
//
//  Created by Azhun Zhu on 2021/10/27.
//

#include <stdio.h>

int main(int args, const char *argv[])
{
 
    int ia[4] = {0, 1, 2, 3};
    int *ip = ia; //ia就是&ia[0]，因此ip指向ia[0]。与此同时ip[1]的含义又和*(ip+1)一样。
    printf("%p\n",ip);
    printf("%p\n",ip+1);
    printf("%d\n",ip[0]);
    printf("%d\n",*(ip+1));
    
    return 0;
}
