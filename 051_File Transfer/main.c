//
//  main.c
//  File Transfer
//
//  *********************************************
//  Description: Transfer file or add connection between different nodes
//  Ex:
//  5
//  C 3 2 -> check if connection exists between node 3 and 2
//  I 3 2 -> add connection between node 3 and 2
//  S     -> end the input and output the number of components
//  *********************************************
//
//  Created by Azhun Zhu on 2022/2/28.
//

#include <stdio.h>

#define MaxSize 10
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

void Initialization( SetType , int );
void Input_connection( SetType );
void Check_connection( SetType );
void Check_network( SetType , int );

int main(int argc, const char * argv[]) {
//初始化集合；
// do {
//        读入一条指令；
//        处理指令；
//} while （没结束）；
//return 0；
    SetType S;
    int n;
    char in;
    scanf("%d\n", &n);
    Initialization( S, n );
    do {
        scanf("%c", &in);
        switch (in) {
            case 'I': Input_connection( S ); break;
            case 'C': Check_connection( S ); break;
            case 'S': Check_network( S, n ); break;
            default:
                break;
        }
    } while (in != 'S');
    return 0;
}

//SetName Find( SetType S, ElementType X){
//    for (; S[X]>=0; X=S[X]) ;
//    return X;
//}

// Find 路径压缩
SetName Find( SetType S, ElementType X){
    if ( S[X] < 0) return X;
    else return S[X] = Find(S, S[X]);
}

//// 根据树高 按秩归并
//void Union( SetType S, SetName Root1, SetName Root2){
//    if ( S[Root2] < S[Root1])
//        S[Root1] = Root2;
//    else{
//        if ( S[Root1] == S[Root2] ) S[Root1]--;
//        S[Root2] = Root1;
//    }
//}

// 根据树的规模 按秩归并
void Union( SetType S, SetName Root1, SetName Root2){
    if ( S[Root2] < S[Root1]){
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    else{
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}

void Initialization( SetType S, int n){
    int i;
    for (i=0; i<n; i++) {
        S[i] = -1;
    }
}

void Input_connection( SetType S){
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u-1);
    Root2 = Find(S, v-1);
    if ( Root1 != Root2) {
        Union(S, Root1, Root2);
    }
}

void Check_connection( SetType S){
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u-1);
    Root2 = Find(S, v-1);
    if (Root1 == Root2)
        printf("yes\n");
    else printf("no\n");
}

void Check_network( SetType S, int n){
    int i, counter = 0;
    for (i=0; i<n; i++) {
        if ( S[i] < 0) counter++;
    }
    if (counter == 1) printf("The network is connected.\n");
    else printf("There are %d components.\n", counter);
}
