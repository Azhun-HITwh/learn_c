//
//  dump_word_array.c
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/10.
//

#include <stdio.h>
#include "word_manage_array.h"

void dump_word(FILE *fp){
    int i;
    
    for (i = 0; i < num_of_word; i++) {
        fprintf(fp, "%-20s%5d\n",
                word_array[i].name, word_array[i].count);
    }
}
