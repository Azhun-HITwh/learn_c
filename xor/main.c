//
//  main.c
//  xor
//
//  Created by Azhun Zhu on 2022/1/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(void){
    
    int orig_ch, new_ch;
    
    while ((orig_ch = getchar()) != EOF) {
        
        new_ch = orig_ch ^ KEY;
        
        if ((isprint(new_ch)) && (isprint(orig_ch))) {
            putchar(new_ch);
        }
        
        else
            putchar(orig_ch);
    }
    
    return 0;
    
}
