//
//  crosslist.h
//  cross_linked_list
//
//  Created by Azhun Zhu on 2022/5/26.
//

#ifndef crosslist_h
#define crosslist_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct OLNode{
    int row, col;
    ElementType value;
    struct OLNode *right, *down;
} OLNode, *OLink;

typedef struct{
    OLink *rowhead, *colhead;
    int rows, cols, nums;
} CrossList, *PCrossList;

#endif /* crosslist_h */
