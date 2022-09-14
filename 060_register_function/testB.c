//
//  testB.c
//  learnc
//
//  Created by Azhun Zhu on 2022/9/14.
//

/*B Module
testB.c文件
实现注册函数
实现事件触发回调*/
#include "test.h"

pf_callback g_ptrfun;

int Register_Callback_Fun(Compute_ST *registed_fun)
{
    if(1 != registed_fun->index)
    {
        printf("Registe failed.\n");
        return -1;
    }
    g_ptrfun = registed_fun->function;
    return 0;
}

void mgmtb_fun(int event)
{
    g_ptrfun(event);
}


