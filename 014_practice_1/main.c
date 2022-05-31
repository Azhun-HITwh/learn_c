//
//  main.c
//  practice_1
//
//  Created by Azhun Zhu on 2021/11/1.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i, j, k;
    int counter = 0;
    for (i=1; i<5; i++)
    {
        for (j=1; j<5; j++)
        {
            for (k=1; k<5; k++)
            {
                if (i!=j && i!=k && j!=k)
                {
                    counter++;
                    printf("%d\n", 100*i + 10*j + k);
                }
            }
        }
    }
    printf("total: %d\n", counter);
}
