#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n, m, source;
int arr[10010][10010];
int dist[10010];
int vis[10010];
vector<int> q;
void FindMinDist() {
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
	}
}
void UpdateDist(int x) {
	for (int i = 1; i <= n; ++i) {
		if (arr[x][i] > 0) {
			if (dist[i] > 0)
				dist[i] = min(dist[i], dist[x] + arr[x][i]);
			else
				dist[i] = dist[x] + arr[x][i];
		}
	}
}
void Dijkstra() {
	vis[source] = true;
	q.push_back(source);
	for (int i = 1; i <= n; ++i) {
		if (arr[source][i] > 0)
			dist[i] = arr[source][i];
	}
	while (q.size() != n) {
		FindMinDist();
		UpdateDist(q.back());
	}
}
int main() {
	cin >> n >> m >> source;
	int a, b, len;
	memset(arr, -1, sizeof(arr));
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> len;
		if (arr[a][b] > 0 && len < arr[a][b])
			arr[a][b] = len;
		else if(arr[a][b] < 0)
			arr[a][b] = len;
	}
	Dijkstra();
	for (int i = 1; i <= n; ++i) {
		if (i == source)
			cout << 0 << ' ';
		else if (dist[i] == -1)
			cout << INT_MAX << ' ';
		else
			cout << dist[i] << ' ';
	}
}