//
//  main.c
//  graphy
//
//  Created by Azhun Zhu on 2022/3/1.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 5
typedef int WeightType;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

typedef struct Gnode *PtrToGNode;
typedef int DataType;
struct Gnode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[];
};

typedef PtrToGNode MGraph;
typedef int Vertex;

MGraph CreateGraph(int VertexNum){
    Vertex V, W;
    MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct Gnode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    
    for (V=0; V<Graph->Nv; V++) {
        for(W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = 0;
    }
    return Graph;
}

typedef struct Enode *PtrToENode;
struct Enode {
    Vertex V1, V2;
    WeightType Weight;
//    DataType Data[];
};

typedef PtrToENode Edge;

void InsertEdge( MGraph Graph, Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph(void){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct Enode));
        for (i=0; i<Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }
    for (V=0; V<Graph->Nv; V++)
        scanf(" %d", &(Graph->Data[V]));
    return Graph;
}
