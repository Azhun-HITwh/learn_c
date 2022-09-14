//
//  TestA.c
//  learnc
//
//  Created by Azhun Zhu on 2022/9/14.
//

/*A Module*/
/*TestA.c 文件
实现回调函数*/
#include "test.h"

void callback_fun(int event)
{
    switch(event)
    {
        case 1:
            {
                printf("ABCDEFG.\n");
                
            }
            break;
        case 2:
            {
                printf("abcdefg.\n");
            }
            break;
        case 3:
            {
                printf("1234567.\n");
            }
            break;
        case 4:
            {
                printf("7654321.\n");
            }
            break;
        default:
            {
                printf("New event, %d.\n",event);
            }
    }
}

int main()
{
    int event = 0;
    Compute_ST ptr_compute;
    
    ptr_compute.index = 1;
    ptr_compute.function = callback_fun;
    //注册回调函数
    if(-1 == Register_Callback_Fun(&ptr_compute))
    {
        printf("Registe failed.\n");
    }
    
    for(;;)
    {
        printf("Enter number:");
        scanf("%d", &event);
        
        if(event == 0)
        {
            return 0;
        }
        //触发事件
        mgmtb_fun(event);
    }
    return 0;
}




