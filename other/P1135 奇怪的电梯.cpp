#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int n, a, b;
int num[210];
struct info {
	int floor;
	int mode;
	int steps;
	info(int x, int y, int z) :floor(x), mode(y), steps(z) { }
};
int visited[210][2];
queue<info> q;
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	q.push(info(a, 1, 0));
	while (!q.empty()) {
		info tmp = q.front();
		if (visited[tmp.floor][tmp.mode]) {
			q.pop();
			continue;
		}
		visited[tmp.floor][tmp.mode] = true;
		if (tmp.floor == b) {
			cout << tmp.steps;
			return 0;
		}
		int up = tmp.floor + num[tmp.floor - 1];
		int down = tmp.floor - num[tmp.floor - 1];
		if (up <= n)
			q.push(info(up, 1, tmp.steps + 1));
		if (down >= 1)
			q.push(info(down, 0, tmp.steps + 1));
		q.pop();
	}
	cout << -1;
}