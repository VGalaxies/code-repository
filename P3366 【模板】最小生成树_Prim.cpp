#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int arr[5010][5010];
int dist[5010];
int vis[5010];
int total;
vector<int> q;
int FindMinDist() {
	int tmp = INT_MAX;
	int mem = 0;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] < tmp && dist[i] > 0 && vis[i] == false) {
			tmp = dist[i];
			mem = i;
		}
	}
	if (tmp != INT_MAX) {
		vis[mem] = true;
		q.push_back(mem);
		return tmp;
	}
	else
		return 0;
}
void UpdateDist(int x) {
	for (int i = 1; i <= n; ++i) {
		if (arr[i][x] > 0) {
			if (dist[i] > 0)
				dist[i] = min(arr[i][x], dist[i]);
			else
				dist[i] = arr[i][x];
		}
	}
}
int main() {
	cin >> n >> m;
	int row, col, len;
	memset(arr, -1, sizeof(arr));
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < m; ++i) {
		cin >> row >> col >> len;
		if (len < arr[row][col] || arr[row][col] < 0) {
			arr[row][col] = len;
			arr[col][row] = len;
		}
	}
	vis[1] = true;
	q.push_back(1);
	total += FindMinDist();
	for (int i = 1; i <= n; ++i) {
		if (arr[i][1] > 0)
			dist[i] = arr[i][1];
	}
	while (q.size() != n) {
		int test = FindMinDist();
		if (test == 0) {
			cout << "orz";
			return 0;
		}
		else {
			UpdateDist(q.back());
			total += test;
		}
	}
	cout << total;
}