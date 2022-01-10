//
//  dump_word_LinkedList.c
//  word_count
//
//  Created by Azhun Zhu on 2022/1/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "word_manage_linkedlist.h"

void dump_word(FILE *fp){
    Word *pos;
    
    for (pos = word_header; pos; pos = pos->next) {
        fprintf(fp, "%-20s%5d\n", pos->name, pos->count);
    }
}
