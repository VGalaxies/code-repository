#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/* ͼ���ڽӾ����ʾ�� */
#define MaxVertexNum 500	/* ��󶥵�����Ϊ500 */
#define INFINITY 65535		/* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;      /* �����<V1, V2> */
	WeightType Dist, Cost;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType Dist[MaxVertexNum][MaxVertexNum]; /* ���� */
	WeightType Cost[MaxVertexNum][MaxVertexNum]; /* ���� */
	Vertex S, D; /* ��㡢�յ� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */

MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildGraph();

/* �ڽӾ���洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
#define ERROR -1
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]);
void Dijkstra(MGraph Graph, int dist[], int cost[], Vertex S);

int main()
{
	int* dist, * cost;
	MGraph Graph = BuildGraph();
	dist = (int*)malloc(sizeof(int) * Graph->Nv);
	cost = (int*)malloc(sizeof(int) * Graph->Nv);
	Dijkstra(Graph, dist, cost, Graph->S);
	printf("%d %d\n", dist[Graph->D], cost[Graph->D]);

	return 0;
}

MGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->Dist[V][W] = Graph->Cost[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->Dist[E->V1][E->V2] = E->Dist;
	Graph->Cost[E->V1][E->V2] = E->Cost;
	/* ��������ͼ����Ҫ�����<V2, V1> */
	Graph->Dist[E->V2][E->V1] = E->Dist;
	Graph->Cost[E->V2][E->V1] = E->Cost;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	scanf("%d", &(Graph->Ne));   /* ������� */
	scanf("%d %d", &(Graph->S), &(Graph->D)); /* ������㡢�յ� */
	if (Graph->Ne != 0) { /* ����б� */
		E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
		/* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d %d", &E->V1, &E->V2, &E->Dist, &E->Cost);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* ����δ����¼������dist��С�� */
	Vertex MinV, V;
	int MinDist = INFINITY;
	for (V = 0; V < Graph->Nv; V++) {
		if (collected[V] == 0 && dist[V] < MinDist) {
			/* ��Vδ����¼����dist[V]��С */
			MinDist = dist[V]; /* ������С���� */
			MinV = V; /* ���¶�Ӧ���� */
		}
	}
	if (MinDist < INFINITY) /* ���ҵ���Сdist */
		return MinV; /* ���ض�Ӧ�Ķ����±� */
	else return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
}

void Dijkstra(MGraph Graph, int dist[], int cost[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->Dist[S][V];
		cost[V] = Graph->Cost[S][V];
		collected[V] = 0;
	}
	dist[S] = cost[S] = 0;
	collected[S] = 1; /* �Ƚ�������뼯�� */
	while (1) {
		/* V = δ����¼������dist��С�� */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* ��������V������ */
			break;      /* �㷨���� */
		collected[V] = 1;  /* ��¼V */
		for (W = 0; W < Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
			/* ��W��V���ڽӵ㲢��δ����¼ */
			if (collected[W] == 0 && Graph->Dist[V][W] < INFINITY) {
				/* ����¼Vʹ��dist[W]��С */
				if (dist[V] + Graph->Dist[V][W] < dist[W]) {
					/* ����dist[W] */
					dist[W] = dist[V] + Graph->Dist[V][W];
					/* ����cost[W] */
					cost[W] = cost[V] + Graph->Cost[V][W];
				}
				/* ���ߵȳ����Ǹ����� */
				else if (dist[V] + Graph->Dist[V][W] == dist[W] &&
					cost[V] + Graph->Cost[V][W] < cost[W]) {
					/* ����cost[W] */
					cost[W] = cost[V] + Graph->Cost[V][W];
				}
			}
	} /* while����*/
}