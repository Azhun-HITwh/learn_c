//
//  main.c
//  function
//
//  Created by Azhun Zhu on 2021/10/25.
//

#include <stdio.h>

static void delete_string(char str[], char ch);
int main() {
    extern void enter(char str[]);
    extern void print(char str[]);
    char c, str[100];
    enter(str);
    scanf(" %c",&c);
    delete_string(str, c);
    print(str);
    return 0;
}

static void delete_string(char str[], char ch)
{
    int i, j;
    for(i=j=0;str[i]!='\0';i++)
    {
        if(str[i]!=ch)
            str[j++]=str[i];
    }
    str[i]='\0';
}
