#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
int n;
char wall[16][16];
int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i, getchar())
		for (int j = 0; j < n; ++j)
			scanf("%c", &wall[i][j]);

		
}