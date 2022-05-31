//
//  main.c
//  polynomial
//
//  Created by Azhun Zhu on 2022/2/17.
//

#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coef;
    int expon;
    struct PolyNode * link;
};

typedef struct PolyNode* Polynomial;

void Attach(int, int, Polynomial *);
Polynomial Add(Polynomial, Polynomial);
Polynomial ReadPoly(void);


int main(int argc, const char * argv[]) {
    
    Polynomial P1, P2, P3;
    int flag = 0; // used to format output
    
    P1 = ReadPoly();
    P2 = ReadPoly();
    P3 = Add(P1, P2);
    while (P3) {
        if (!flag)
            flag = 1;
        else
            printf("+");
        printf(" %dx^%d ", P3->coef, P3->expon);
        P3 = P3->link;
    }
    printf("\n");
    
    return 0;
}

void Attach(int c, int e, Polynomial *pRear){
    Polynomial P;
    
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

Polynomial ReadPoly(void){
    
    Polynomial P, Rear, t;
    int c, e, N;
    
    printf("Please input one polynomial expression (#Total_items #coef #expon):\n");
    scanf("%d", &N);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while (N--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    t = P;
    P = P->link;
    free(t);
    
    return P;
}

Polynomial Add(Polynomial P1, Polynomial P2){
    
    Polynomial t1, t2, Rear, P, temp;
    int sum;
    
    t1 = P1;
    t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    
    while (t1 && t2) {
        if (t1->expon == t2->expon) {
            sum = t1->coef + t2->coef;
            if (sum) {
                Attach(sum, t1->expon, &Rear);
                t1 = t1->link;
                t2 = t2->link;
            }
            else{
                t1 = t1->link;
                t2 = t2->link;
            }
        }
        else if (t1->expon > t2->expon){
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link;
        }
        else{
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
        }
    }
    while (t1) {
        Attach(t1->coef, t1->expon, &Rear);
        t1 = t1->link;
    }
    while (t2) {
        Attach(t2->coef, t2->expon, &Rear);
        t2 = t2->link;
    }
    temp = P;
    P = P->link;
    free(temp);
    
    return P;
}
