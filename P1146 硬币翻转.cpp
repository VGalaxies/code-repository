#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[110];
int n;
void reverse(int* ori,int skip) {
	for (int i = 0; i < n; ++i) {
		if (i != skip)
			ori[i] = !ori[i];
	}
}
int main() {
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		reverse(arr, i);
		for (int i = 0; i < n; ++i)
			printf("%d", arr[i]);
		printf("\n");
	}
	
}