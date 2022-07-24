#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

int max(int a, int b) {
	return a > b ? a : b;
}

int V, E;
int graph[110][110];
int dist[110][110];
int from, to, value;
int ans = MAX;
int index, tmp;

int main() {
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= E; ++i) {
		scanf("%d%d%d", &from, &to, &value);
		graph[from][to] = value;
		graph[to][from] = value;
	}
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (graph[i][j])
				dist[i][j] = graph[i][j];
			else if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = MAX;
		}
	}
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	for (int i = 1; i <= V; ++i) {
		tmp = 0;
		for (int j = 1; j <= V; ++j) {
			if (dist[i][j] > tmp)
				tmp = dist[i][j];
		}
		if (tmp == 0)
			continue;
		if (tmp < ans) {
			ans = tmp;
			index = i;
		}
	}
	if (ans != MAX)
		printf("%d %d", index, ans);
	else
		printf("0");
}