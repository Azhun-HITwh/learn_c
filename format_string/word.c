//
//  word.c
//  format_string
//
//  Created by Azhun Zhu on 2022/1/5.
//

#include <stdio.h>
#include "word.h"

int read_char(void){
    int ch = getchar();
    if (ch == '\n' || ch == '\t') {
        return  ' ';
    }
    return ch;
}

int read_word(char *word, int len){
    int ch, i;
    
    while ((ch = read_char()) == ' ') {
        ;
    }
    
    i = 0;
    
    while (ch != ' ' && ch != EOF) {
        if(i < len)
            word[i++] = ch;
        ch = read_char();
    }
    word[i] = '\0';
    return 0;
}
