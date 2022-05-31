//
//  main.c
//  bt_static_array
//
//  Created by Azhun Zhu on 2022/2/22.
//

#include <stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]){
    int N, i;
    int *check = NULL;
    char cl, cr;
    Tree Root = 0;
    scanf("%d\n", &N);
    if (N) {
        for (i=0; i<N; i++) {
            check[i] = 0;
        }
        for (i=0; i<N; i++) {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
            if (cl != '-') {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else T[i].Left = Null;
            if (cr != '-') {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else T[i].Right = Null;
        }
        for (i=0; i<N; i++) {
            if (!check[i]) {
                break;
            }
        }
        Root = i;
    }
    
    return Root;
}

int Isomorphic(Tree R1, Tree R2){
    if ((R1 == Null)&&(R2 == Null)) {
        return 1;
    }
    if (((R1 == Null)&&(R2 != Null)) || ((R1 != Null)&&(R2 == Null))) {
        return 0;
    }
    if (T1[R1].Element != T2[R2].Element) {
        return 0;
    }
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) {
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }
    return 0;
}
