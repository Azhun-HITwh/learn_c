//
//  word_manage.h
//  learnc
//
//  Created by Azhun Zhu on 2022/1/10.
//

#ifndef word_manage_h
#define word_manage_h
#include <stdio.h>

void word_initialize(void);
void add_word(char *word);
void dump_word(FILE *file);
void word_finalize(void);


#endif /* word_manage_h */
