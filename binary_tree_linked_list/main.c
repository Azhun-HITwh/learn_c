//
//  main.c
//  binary_tree_linked_list
//
//  Created by Azhun Zhu on 2022/2/21.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreOrderTraversal(BinTree BT){
    if (BT) {
        printf("%d", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

void InOrderTraversal(BinTree BT){
    if (BT) {
        InOrderTraversal(BT->Left);
        printf("%d", BT->Data);
        InOrderTraversal(BT->Right);
    }
}
