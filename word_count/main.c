//
//  main.c
//  word_count
//
//  Created by Azhun Zhu on 2022/1/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "get_word.h"
#include "word_manage_array.h"

#define WORD_LEN_MAX (1024)

int main(int argc, const char * argv[]) {
    
    char buf[WORD_LEN_MAX];
    FILE *fp;
    
    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], 'r');
        if (fp == NULL) {
            fprintf(stderr, "%s : %s can not open.\n", argv[0], argv[1]);
            exit(1);
        }
    }
    
    word_initialize();
    
    while (get_word(buf, WORD_LEN_MAX, fp) != EOF) {
        add_word(buf);
    }
    
    dump_word(stdout);
    
    word_finalize();
    
    return 0;
}
