//
//  main.c
//  enum
//
//  Created by Azhun Zhu on 2021/10/27.
//

#include <stdio.h>
#include <stdlib.h>

/*关于枚举在switch中的使用，输入使用 scanf() ，是不安全的，因为他在读取字符串的时候不会检查边界，可能会造成内存泄露，在 Visual Studio 中编译会报错，推荐使用 scanf_s() 。*/
int main(int argc, const char * argv[])
{
    enum color { red = 1, green, blue};
    
    enum color favourite_color;
    printf("Please enter the color you like: (1. red, 2. green, 3. blue): \n");
    scanf("%u", &favourite_color);
    switch (favourite_color)
    {
        case red:
            printf("You like red!");
            break;
        case green:
            printf("You like green!");
            break;
        case blue:
            printf("You like blue!");
            break;
        default:
            printf("No color you like!");
    }
    return 0;
}
