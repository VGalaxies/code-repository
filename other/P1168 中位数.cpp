#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n;
int arr[100010];
int tmp[100010];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 1; i <= n; i = i + 2) {
		memcpy(tmp, arr, i * sizeof(int));
		sort(tmp, tmp + i);
		cout << tmp[(i - 1) / 2] << endl;
	}	
}