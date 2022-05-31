//
//  main.c
//  double_linked_list
//
//  Created by Azhun Zhu on 2022/5/30.
//

#include <stdio.h>
#include "doubly_linked_list_node.h"

int main(int argc, const char * argv[]) {
    
    Node *rootp = (Node *)malloc(sizeof(Node));
    
    dll_insert(rootp, 10);
    dll_insert(rootp, 13);
    dll_insert(rootp, 5);
    
    print_list(rootp);
    
    free(rootp);
    
    return 0;
}
