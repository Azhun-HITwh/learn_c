//
//  average.c
//  variable_para
//
//  Created by Azhun Zhu on 2022/5/29.
//


#include "average.h"

float average(int n_values, ... ){
    va_list var_arg;
    int count;
    float sum = 0;
    
    va_start(var_arg, n_values);
    
    for (count = 0; count < n_values; count += 1) {
        sum += va_arg(var_arg, int);
    }
    
    va_end(var_arg);

    return sum / n_values;
}
