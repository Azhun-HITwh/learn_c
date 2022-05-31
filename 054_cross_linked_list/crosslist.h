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

bool InitCrossList(PCrossList L, int row, int col);
int AddCrossList_Array(PCrossList L, const ElementType A[]);
int AddCrossList_Matrix(PCrossList L, const ElementType A[L->rows][L->cols]);
int AddCrossList(PCrossList L, ElementType k, int m, int n);
int DeleteAllCrossList(PCrossList L, ElementType k);
int DeleteCrossList(PCrossList L, int m, int n);
int DestoryCrossList(PCrossList *L);
void PrintCrossList(const PCrossList L);

#endif /* crosslist_h */
