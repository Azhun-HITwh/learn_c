//
//  word_manage_linkedlist.h
//  learnc
//
//  Created by Azhun Zhu on 2022/1/10.
//

#ifndef word_manage_linkedlist_h
#define word_manage_linkedlist_h

#include "word_manage.h"

typedef struct Word_tag{
    char *name;
    int count;
    struct Word_tag *next;
}Word;


extern Word *word_header;


#endif /* word_manage_linkedlist_h */
