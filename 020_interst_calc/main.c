//
//  main.c
//  interst_calc
//
//  Created by Azhun Zhu on 2021/12/26.
//

#include <stdio.h>

#define NUM_RATES (int)sizeof(value)/sizeof(value[0])
#define INITIAL_BALANCE 100.00

int main(int argc, const char * argv[]) {
    int rate;
    int year;
    double value[5];
    
    printf("Enter intrest rate: ");
    scanf("%d", &rate);
    printf("Enter number of years: ");
    scanf("%d", &year);
    
    printf("\nYears");
    for (int i = 0; i < NUM_RATES; i++) {
        printf("%7d%%", rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");
    
    for (int i = 0; i < year; i++) {
        printf("%3d   ", i+1);
        for (int j = 0; j < NUM_RATES; j++) {
            value[j] += value[j] * (rate + j) / 100;
            printf("%8.2f", value[j]);
        }
        printf("\n");
    }
    return 0;
}
