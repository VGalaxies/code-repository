#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m, n;
int queue[1010];
int memory[110];
int count = 0;
int mem_index = 0;
int search(int n) {
	for (int i = 0; i < m; ++i)
		if (memory[i] == n)
			return 1;
	return 0;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &queue[i]);
		if (queue[i] == 0)
			queue[i] = -1;
		if (!search(queue[i])) {
			count++;
			memory[mem_index] = queue[i];
			mem_index = (mem_index + 1) % m;
		}
	}
	printf("%d", count);
}