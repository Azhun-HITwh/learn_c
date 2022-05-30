//
//  doubly_linked_list_node.c
//  double_linked_list
//
//  Created by Azhun Zhu on 2022/5/30.
//

#include "doubly_linked_list_node.h"

int dll_insert( Node *rootp, int value){
    
    Node *this;
    Node *next;
    Node *newnode;
    
    for (this = rootp; (next = this->fwd) != NULL; this = next) {
        if (next->value == value) {
            return 0;
        }
        if (next->value > value) {
            break;
        }
    }
    
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL) {
        return -1;
    }
    newnode->value = value;
    
    if (next != NULL) {
        if (this != rootp) {
            newnode->fwd = next;
            this->fwd = newnode;
            newnode->bwd = this;
            next->bwd = newnode;
        }
        else {
            newnode->fwd = next;
            rootp->fwd = newnode;
            newnode->bwd = NULL;
            next->bwd = newnode;
        }
    }
    else {
        if (this != rootp) {
            newnode->fwd = NULL;
            this->fwd = newnode;
            newnode->bwd = this;
            rootp->bwd = newnode;
        }
        else {
            newnode->fwd = NULL;
            newnode->bwd = NULL;
            rootp->fwd = newnode;
            rootp->bwd = newnode;
        }
    }
    return 1;
}

void print_list(Node *rootp){
    Node *tmp = NULL;
    for (tmp = rootp; tmp->fwd; tmp = tmp->fwd) {
        printf("the value: %d\n", tmp->fwd->value);
    }
}
