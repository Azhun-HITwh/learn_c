//
//  main.c
//  variable_para
//
//  Created by Azhun Zhu on 2022/5/29.
//

#include "average.h"

int main(int argc, const char * argv[]) {
    float avg;
    avg = average(6, 1, 2, 3, 4, 5, 6);
    printf("avg: %f\n", avg);
    return 0;
}
