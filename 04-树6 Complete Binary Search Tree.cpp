#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n;
int ori[2020];
int index[] = { 0,1,1,2,3,3,3,4,5,6,7,7,7,7,7 };


int compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int getIndex(int x) {
	return index[x];
}

void solve(int l,int r) {
	if (l > r)
		return;
	int index = getIndex(r - l) + l;
	printf("%d ", ori[index]);
	solve(l, index - 1);
	solve(index + 1, r);

}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ori[i]);
	qsort(ori, n, sizeof(int), compare);
	solve(0, n - 1);

}