//
//  main.c
//  io
//
//  Created by Azhun Zhu on 2021/11/3.
//

#include <stdio.h>

int main()
{
//    char c[100];
//    printf("Enter a value:\n");
//    fgets(c, 100, stdin);
//
//    printf("\nyou entered:");
//    fputs(c, stdout);

    int i;
    char c;
    scanf("%d", &i);
    while((c=getchar())==' ' || c=='\n')
    {
        c = getchar();
    }
    return 0;

}
