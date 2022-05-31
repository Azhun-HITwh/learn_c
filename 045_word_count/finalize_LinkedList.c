//
//  finalize_LinkedList.c
//  word_count
//
//  Created by Azhun Zhu on 2022/1/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "word_manage_linkedlist.h"

void word_finalize(void){
    Word *temp;
    
    while (word_header != NULL) {
        temp = word_header;
        word_header = word_header->next;
        
        free(temp->name);
        free(temp);
    }
}
