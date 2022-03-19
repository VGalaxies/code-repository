#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, E;
int graph[10][10];
int vis[10];
int from, to;
int queue[100];
int head = 0, tail = 0;

void DFS(int from) {
	vis[from] = 1;
	for (int i = 0; i < N; ++i) {
		if (!vis[i] && graph[from][i]) {
			printf("%d ", i);
			DFS(i);
		}
	}
}

void BFS(int from) {
	vis[from] = 1;
	while (head < tail) {
		int from = queue[head++];
		for (int i = 0; i < N; ++i) {
			if (!vis[i] && graph[from][i]) {
				vis[i] = 1;
				queue[tail++] = i;
				printf("%d ", i);
			}
		}
	}

}

int main() {
	scanf("%d%d", &N, &E);
	for (int i = 0; i < E; ++i) {
		scanf("%d%d", &from, &to);
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			printf("{ %d ", i);
			DFS(i);
			printf("}\n");
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			queue[tail++] = i;
			printf("{ %d ", i);
			BFS(i);
			printf("}\n");
		}
	}
}