//
//  main.c
//  max_min_pointer
//
//  Created by Azhun Zhu on 2022/1/5.
//

#include <stdio.h>

#define SIZE 5

void max_min(int a[], int len, int *max, int *min);

int main(int argc, const char * argv[]) {
    int a[SIZE];
    int max, min, i;
    
    printf("Enter 5 numbers:\n");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", a+i);
    }
    max_min(a, SIZE, &max, &min);
    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    return 0;
}

void max_min(int a[], int len, int *max, int *min){
    int i;
    for (i = 0; i < len; i++) {
        if (*max < a[i]) {
            *max = a[i];
        }
        else if (*min > a[i]){
            *min = a[i];
        }
    }
}
