//
//  hanio_step.c
//  learnc
//
//  Created by Azhun Zhu on 2022/9/20.
//

#include "hanio_step.h"

int Hanio_Step(int num){
    if (1 == num) {
        return 1;
    }
    else{
        return 2 * Hanio_Step(num-1) + 1;
    }
}

void Hanio_print(int n, char a, char b, char c){
    if (1 ==n) {
        printf("%c->%c\n", a, c);
    }
    else{
        Hanio_print(n-1, a, c, b);
        printf("%c->%c\n",a, c);
        Hanio_print(n-1, b, a, c);
    }
}

int main(void){
    int num = 0;
    for(;;){
        scanf("%d", &num);
        int ret = Hanio_Step(num);
        printf("total layer:%d;total steps:%d\n", num, ret);
        Hanio_print(num, 'A', 'B', 'C');
    }
    return 0;
}
