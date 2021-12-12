//
//  main.c
//  wild_pointer
//
//  Created by Azhun Zhu on 2021/12/12.
//

#include <stdio.h>

int *test(void){
    static int a = 10;
    printf("address...%p\n", &a);
    return &a;
}

int main(int argc, const char * argv[]) {
    int *p = test();
    *p = 20;
    printf("address in main...%p\n", p);
    printf("%d\n", *p);
    return 0;
}
