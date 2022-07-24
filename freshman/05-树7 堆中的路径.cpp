#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXN 1001
#define MIN -10001

int heap[MAXN], size;

void Create() {
	size = 0;
	heap[size] = MIN;
}

void Insert(int x) {
	int i;
	for (i = ++size; heap[i / 2] > x; i /= 2) {
		heap[i] = heap[i / 2];
	}
	heap[i] = x;
}

int n, m, x;
int main() {
	Create();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		Insert(x);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &x);
		while (x > 0) {
			if (x == 1)
				printf("%d", heap[x]);
			else
				printf("%d ", heap[x]);
			x /= 2;
		}
		printf("\n");
	}
}