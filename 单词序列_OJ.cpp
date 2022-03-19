#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;
int steps = 1;
int min_steps = 2147483647;
char ori[10];
char str[10];
char dict[50][10];
int visited[50];
int distinct(char* a, char* b) {
	int count = 0;
	int len = strlen(a);
	for (int i = 0; i < len; ++i)
		if (a[i] != b[i])
			count++;
	return count;
}
void DFS(char* a, int index) {
	if (distinct(a, str) == 1) {
		steps++;
		min_steps = min(min_steps, steps);
		steps--;
		return;
	}
	for (int i = 0; i < index; ++i) {
		if (distinct(a, dict[i]) == 1 && visited[i] == false) {
			visited[i] = true;
			steps++;
			DFS(dict[i], index);
			steps--;
			visited[i] = false;
		}
	}
	return;
}
int main() {
	int index = 0;
	scanf("%s%s", ori, str);
	while (cin >> dict[index++]);
	DFS(ori, index);
	if (min_steps == 2147483647)
		printf("0");
	else
		printf("%d", min_steps);
}