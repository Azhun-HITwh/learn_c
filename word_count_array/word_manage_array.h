//
//  word_manage_array.h
//  stackADT
//
//  Created by Azhun Zhu on 2022/1/10.
//

#ifndef word_manage_array_h
#define word_manage_array_h


#include "word_manage.h"


typedef struct {
    char *name;
    int count;
}Word;

#define WORD_NUM_MAX (10000)

extern Word word_array[];
extern int num_of_word;

#endif /* word_manage_array_h */
