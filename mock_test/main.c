//
//  main.c
//  mock_test
//
//  Created by Azhun Zhu on 2021/11/21.
//

#include <stdio.h>

int main()
{
    FILE *fp;
    if((fp = fopen("/Users/azhun/learnc/mock_test/test.txt", "r")) != NULL)
        while(fgetc(fp) != EOF)
            printf("char...%s", fgets(fp));
            putchar(fgetc(fp));
    else
        printf("fail to open! \n");
    fclose(fp);

    return 0;
}

