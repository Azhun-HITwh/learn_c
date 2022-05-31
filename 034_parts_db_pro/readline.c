//
//  readline.c
//  parts_db_pro
//
//  Created by Azhun Zhu on 2022/1/8.
//

#include <stdio.h>
#include <ctype.h>
#include "readline.h"

char *read_line(char str[], int len){
    int ch, i = 0;
    
    while (isspace(ch = getchar())) {
        ;
    }
    
    while ((ch != '\n' && ch != EOF)) {
        if (i < len) {
            str[i] = ch;
            i++;
            ch = getchar();
        }
    }
    str[i] = '\0';
    
    return str;
}
