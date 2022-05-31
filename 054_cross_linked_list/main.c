//
//  main.c
//  cross_linked_list
//
//  Created by Azhun Zhu on 2022/5/26.
//

#include "crosslist.h"

int main(int argc, const char * argv[]) {
    CrossList L;
    PCrossList pL = &L;
    InitCrossList(pL, 4, 5);
    int A[20] = {1,0,0,5,0,0,2,0,0,0,0,0,0,0,3,2,0,0,0,1};
    AddCrossList_Array(pL, A);
    AddCrossList(pL, 6, 2, 4);
    PrintCrossList(pL);
    DeleteAllCrossList(pL, 2);
    PrintCrossList(pL);
    DestoryCrossList(&pL);
    PrintCrossList(pL);
    return 0;
}
