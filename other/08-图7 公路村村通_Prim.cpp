#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 1010
#define INF 65535
#define ERROR -1

typedef int Vertex;
typedef int WeightType; 

typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum) {
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for (V = 1; V <= Graph->Nv; ++V) {
		Graph->G[V].FirstEdge = NULL;
	}

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E) {
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph() {
	LGraph Graph;
	Edge E;
	int Nv;

	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (int i = 0; i < Graph->Ne; ++i) {
			scanf("%d%d%d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	
	return Graph;
}

WeightType FindWeight(LGraph Graph, Vertex from, Vertex to) {
	for (PtrToAdjVNode Edge = Graph->G[from].FirstEdge; Edge; Edge = Edge->Next) {
		if (Edge->AdjV == to)
			return Edge->Weight;
	}
	return INF;
}

Vertex FindMinDist(LGraph Graph, WeightType dist[]) {
	// 考虑最小堆优化
	Vertex MinV;
	WeightType MinDist = INF;

	for (Vertex V = 1; V <= Graph->Nv; ++V) {
		if (dist[V] != 0 && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	}

	if (MinDist < INF)
		return MinV;
	else
		return ERROR;
}

WeightType Prim(LGraph Graph, LGraph* MST) {
	WeightType dist[MaxVertexNum], TotalWeight, TmpWeight;
	Vertex parent[MaxVertexNum];
	Vertex V, W;
	int Vcount;
	Edge E;

	for (V = 1; V <= Graph->Nv; ++V) {
		dist[V] = FindWeight(Graph, 1, V);
		parent[V] = 1;
	}

	TotalWeight = 0;
	Vcount = 0;

	*MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode));

	dist[1] = 0;
	Vcount++;
	parent[1] = -1;

	while (1) {
		V = FindMinDist(Graph, dist);
		if (V == ERROR)
			break;

		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(*MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		Vcount++;

		for (W = 1; W <= Graph->Nv; ++W) {
			TmpWeight = FindWeight(Graph, V, W);
			if (dist[W] != 0 && TmpWeight < INF) {
				if (TmpWeight < dist[W]) {
					dist[W] = TmpWeight;
					parent[W] = V;
				}
			}
		}
	}

	if (Vcount < Graph->Nv)
		TotalWeight = ERROR;
	return TotalWeight;
}

int main() {
	LGraph Graph, MST = NULL;
	Graph = BuildGraph();
	printf("%d", Prim(Graph, &MST));
}