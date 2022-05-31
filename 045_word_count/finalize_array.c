//
//  finalize.c
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "word_manage_array.h"

void word_finalize(void){
    int i;
    
    for (i = 0; i < num_of_word; i++) {
        free(word_array[i].name);
    }
    
    num_of_word = 0;
}
