//
//  main.c
//  comparator
//
//  Created by Azhun Zhu on 2021/12/27.
//

#define SIZE 5

#include <stdio.h>

void max_min(int *a, int len, int* max, int* min){
    int i;
    
    *max = *min = a[0];
    for (i=0; i< SIZE; i++) {
        if (a[i] > *max) {
            *max = a[i];
        }
        else{
            *min = a[i];
        }
    }
}

int main(int argc, const char * argv[]) {
    int a[SIZE];
    int i, max, min;
    printf("Enter 5 numbers: (press enter to confirm)\n");
    for (i=0; i<SIZE; i++) {
        scanf("%d", &a[i]);
    }
    max_min(a, SIZE, &max, &min);
    printf("max: %d, min: %d\n", max, min);
    
    return 0;
}
