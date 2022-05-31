#  DFS 深搜法

#include <stdio.h>
#include <stdlib.h>

int  b[4],arr[4];//定义两个数组用来类比
int Count=0;//计数器
void DFS(int step){
    if(step==5){
        if(arr[1]!=arr[2]&& arr[1]!=arr[3]&&arr[2]!=arr[3]){//判断哪些符合条件
            Count++;
            printf("%d%d%d\n",arr[1],arr[2],arr[3]);//输出可用排列
        }
        return ;
    }

    for(int i=1;i<=4;i++){
        if(b[i]==0){
            arr[step]=i;
            b[i]=1;//排除重复
            DFS(step+1);//自己调用自己
            b[i]=0;
        }
    }
    return ;
}

int main(void)
{
    DFS(1);
    printf("共有%d种",Count);
    return 0;
}
