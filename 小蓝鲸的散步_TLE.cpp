#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct node {
	int to;
	int weight;
	node(int _to, int _w) :to(_to), weight(_w) {}
	bool operator < (const node& p) {
		return weight > p.weight;
	}
};
vector<node> edges[100010];
bool visited[100010];
int vis;
int n;
int l, r;
int steps;
int ans;
inline void add(int from, int to){
	node p(to, 3);
	edges[from].push_back(p);
}
void DFS(int from) {
	if (vis == n) {
		ans = (ans == 0) ? steps : min(ans, steps);
		return;
	}
	sort(edges[from].begin(), edges[from].end());
	for (int i = 0; i < edges[from].size(); ++i) {
		int to = edges[from][i].to;
		if (!visited[to]) {
			vis++;
			visited[to] = true;
		}
		steps++;
		if (steps > ans && ans)
			return;
		edges[from][i].weight--;
		find_if(edges[to].begin(), edges[to].end(), [=](const node& p) {return p.to == from; })->weight--;
		DFS(to);
	}
}
int main() {
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		if (l > 0) {
			add(i, l);
			add(l, i);
		}
		if (r > 0) {
			add(i, r);
			add(r, i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (edges[i].size() != 1)
			continue;
		memset(visited, 0, sizeof(visited));
		vis = 1;
		steps = 0;
		DFS(i);
	}
	cout << ans;
}