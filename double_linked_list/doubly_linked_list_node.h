//
//  doubly_linked_list_node.h
//  double_linked_list
//
//  Created by Azhun Zhu on 2022/5/30.
//

#ifndef doubly_linked_list_node_h
#define doubly_linked_list_node_h

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
} Node;

int dll_insert( Node *rootp, int value);

void print_list(Node *rootp);

#endif /* doubly_linked_list_node_h */
