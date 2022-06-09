#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int k;
int visited[30];
int pos(int p,int m) {
	int count = 1;//数过了几个人
	while (count < m) {
		if (!visited[p])
			count++;
		p = (p + 1) % (2 * k);
	}
	while (visited[p])
		p = (p + 1) % (2 * k);
	return p;
		
}
int main() {
	cin >> k;
	bool judge = true;
	int count = 0;//排除的人
	int p = 0;
	int i = k + 1;
	for (;; i++) {
		memset(visited, 0, sizeof(visited));
		count = 0;
		p = 0;
		while (count < k) {
			int tmp = pos(p, i);
			if (tmp < k) {
				judge = false;
				break;
			}
			visited[tmp] = true;
			count++;
			while (visited[tmp])
				tmp++;
			p = tmp % (2 * k);
		}
		if (count >= k)
			break;
	}
	cout << i;
}