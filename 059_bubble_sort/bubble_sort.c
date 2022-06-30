//
//  bubble_sort.c
//  learnc
//
//  Created by Azhun Zhu on 2022/6/30.
//

#include "bubble_sort.h"

int * bubble(int list[]){
    
    int size = sizeof(&list);
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    
    return list;
}

int main(int argc, const char * argv[]) {
    int a[7] = {3, 5, 10, 39, 4, 1, 6};
    bubble(a);
    for(int i = 0; i < 7; i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
