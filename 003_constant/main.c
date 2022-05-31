//
//  main.c
//  constant
//
//  Created by Azhun Zhu on 2021/10/20.
//

#include <stdio.h>

#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

int main(void)
{
    int area;
    const int RADIUS = 10;
    const float PI = 3.14;
    float circle_area;
    
    area = LENGTH * WIDTH;
    printf("value of area: %d", area);
    printf("%c", NEWLINE);
    
    circle_area = PI * RADIUS * RADIUS;
    printf("value of circle area: %f", circle_area);
    printf("%c", NEWLINE);
    
    return 0;
}
