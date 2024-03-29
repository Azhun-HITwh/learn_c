//
//  crosslist.c
//  cross_linked_list
//
//  Created by Azhun Zhu on 2022/5/26.
//

#include "crosslist.h"

bool InitCrossList(PCrossList L, int row, int col){
    L->colhead = (OLink *)malloc(row * sizeof(OLink));
    if (L->colhead == NULL) {
        return false;
    }
    for (int i = 0; i < row; i++) {
        L->colhead[i] = NULL;
    }
    L->rowhead = (OLink *)malloc(col * sizeof(OLink));
    if (L->rowhead == NULL) {
        free(L->colhead);
        return false;
    }
    for (int j = 0; j < col; j++) {
        L->rowhead[j] = NULL;
    }
    L->rows = row;
    L->cols = col;
    L->nums = 0;
    return true;
}

int AddCrossList_Array(PCrossList L, const ElementType A[]){
    if (L->nums != 0) {
        return -1;
    }
    OLNode *prow = NULL;
    OLNode *pcol = NULL;
    OLNode *p = NULL;
    int m = L->rows;
    int n = L->cols;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i*n+j] != 0) {
                p = (OLNode*)malloc(sizeof(OLNode));
                p->row = i;
                p->col = j;
                p->down = NULL;
                p->right = NULL;
                p->value = A[i*n+j];
                if (L->rowhead[i] == NULL) {
                    L->rowhead[i] = p;
                }
                else {
                    prow = L->rowhead[i];
                    while (prow->right != NULL) {
                        prow = prow->right;
                    }
                    prow->right = p;
                }
                if (L->colhead[j] == NULL) {
                    L->colhead[j] = p;
                }
                else {
                    pcol = L->colhead[j];
                    while (pcol->down != NULL) {
                        pcol = pcol->down;
                    }
                    pcol->down = p;
                }
                L->nums++;
            }
        }
    }
    return L->nums;
}

int AddCrossList_Matrix(PCrossList L, const ElementType A[L->rows][L->cols]) {
    if (L->nums != 0) {
        return -1;
    }
    OLNode *prow = NULL;    //只能访问right项
    OLNode *pcol = NULL;    //只能访问down项
    OLNode *p = NULL;
    int m = L->rows;
    int n = L->cols;
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                p = (OLNode*)malloc(sizeof(OLNode));
                p->row = i;
                p->col = j;
                p->down = NULL;
                p->right = NULL;
                p->value = A[i][j];
                if (L->rowhead[i] == NULL) {
                    L->rowhead[i] = p;
                }
                else {
                    prow = L->rowhead[i];
                    while (prow->right != NULL) {
                        prow = prow->right;
                    }
                    prow->right = p;
                }
                if (L->colhead[j] == NULL) {
                    L->colhead[j] = p;
                }
                else {
                    pcol = L->colhead[j];
                    while (pcol->down != NULL) {
                        pcol = pcol->down;
                    }
                    pcol->down = p;
                }
                L->nums++;
                count++;
            }
        }
    }
    return count++;
}

int AddCrossList(PCrossList L, ElementType k, int m, int n) {
    if (k == 0 || m < 0 || m >= L->rows || n < 0 || n >= L->cols) {
        return -1;
    }
    OLNode *prow = L->rowhead[m];    //只能访问right项
    OLNode *pcol = L->colhead[n];    //只能访问down项
    OLNode *s = NULL;
    s = prow;
    while (s != NULL) {
        if (s->col == n) {
            break;
        }
        s = s->right;
    }
    if (s != NULL) {
        s->value = k;
        return 0;
    }
    //添加新结点
    s = (OLNode*)malloc(sizeof(OLNode));
    s->value = k;
    s->row = m;
    s->col = n;
    s->right = s->down = NULL;
    if (L->rowhead[m] == NULL) {
        L->rowhead[m] = s;
    }
    else if (L->rowhead[m]->right->col > n) {
        s->right = L->rowhead[m]->right;
        L->rowhead[m] = s;
    }
    else {
        while (prow->right != NULL && prow->right->col < n) {
            prow = prow->right;
        }
        s->right = prow->right;
        prow->right = s;
    }
    if (L->colhead[n] == NULL) {
        L->colhead[n] = s;
    }
    else if (L->colhead[n]->down->row > m) {
        s->down = L->colhead[n]->down;
        L->colhead[n] = s;
    }
    else {
        while (pcol->down != NULL && pcol->down->row < m) {
            pcol = pcol->down;
        }
        s->down = pcol->down;
        pcol->down = s;
    }
    L->nums++;
    return 1;
}

int DeleteAllCrossList(PCrossList L, ElementType k) {
    int i = 0, count = 0;
    OLNode *prow = NULL;    //只能访问right项
    OLNode *pcol = NULL;    //只能访问down项
    OLNode *p = NULL;

    while (i < L->rows) {
        p = L->rowhead[i];
        while (p != NULL && p->value != k) {
            p = p->right;
        }
        if (p == NULL) {
            i++;
            continue;
        }
        prow = L->rowhead[p->row];
        pcol = L->colhead[p->col];
        if (L->rowhead[p->row] == p) {
            L->rowhead[p->row] = p->right;
        }
        else {
            while (prow->right != p) {
                prow = prow->right;
            }
            prow->right = p->right;
        }
        if (L->colhead[p->col] == p) {
            L->colhead[p->col] = p->down;
        }
        else {
            while (pcol->down != p) {
                pcol = pcol->down;
            }
            pcol->down = p->down;
        }
        L->nums--;
        free(p);
        count++;
    }
    return count;
}

int DeleteCrossList(PCrossList L, int m, int n){
    if (m < 0 || m >= L->rows || n < 0) {
        return -1;
    }
    OLNode *prow = L->rowhead[m];
    OLNode *pcol = L->colhead[n];
    if (prow == NULL || pcol == NULL) {
        return 0;
    }
    OLNode *p = NULL;
    p = prow;
    while (p != NULL) {
        if (p->col == n) {
            break;
        }
        p = p->right;
    }
    if (p == NULL) {
        return 0;
    }
    if (L->rowhead[m] == p) {
        L->rowhead[m] = p->right;
    }
    else{
        while (prow->right != p) {
            prow = prow->right;
        }
        prow->right = p->right;
    }
    if (L->colhead[n] == p) {
        L->colhead[n] = p->down;
    }
    else {
        while (pcol->down != p) {
            pcol = pcol->down;
        }
        pcol->down = p->down;
    }
    L->nums--;
    free(p);
    return 1;
}

int DestoryCrossList(PCrossList *L) {
    OLNode *p, *pre;
    for (int i = 0; i < (*L)->rows; i++) {
        p = (*L)->rowhead[i];
        while (p != NULL) {
            pre = p;
            p = p->right;
            free(pre);
        }
    }
    free((*L)->colhead);
    free((*L)->rowhead);
    (*L)->cols = (*L)->rows = (*L)->nums = 0;
    *L = NULL;
    return 0;
}

void PrintCrossList(const PCrossList L) {
    printf("#CrossList\n");
    if (L == NULL || L->nums == 0) {
        return;
    }
    printf("  |");
    for (int i = 0; i < L->cols; i++) {
        printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i < L->cols; i++) {
        printf("------");
    }
    printf("\n");
    OLNode *p = NULL;
    for (int i = 0; i < L->rows; i++) {
        printf("%2d|", i);
        p = L->rowhead[i];
        for (int j = 0; j < L->cols; j++) {
            if (p != NULL && p->col == j) {
                printf("%5d", p->value);
                p = p->right;
            }
            else {
                printf("    *");
            }
        }
        printf("\n");
    }
}
