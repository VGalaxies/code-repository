#include<iostream>
#include<list>
#include<map>
using namespace std;
int n, m;
int total;
int Fa[5010];
int Rank[5010];
void makeSet(int size) {
	for (int i = 1; i <= size; i++) {
		Rank[i] = 1;
		Fa[i] = i;
	}
	return;
}
int find(int x) {
	if (Fa[x] == x)
		return x;
	else
		return find(Fa[x]);
}
inline void merge(int i, int j)
{
	int x = find(i), y = find(j);
	if (Rank[x] <= Rank[y])
		Fa[x] = y;
	else
		Fa[y] = x;
	if (Rank[x] == Rank[y] && x != y)
		Rank[y]++;
}
struct edge{
	int a;
	int b;
	edge(int _a, int _b) :a(_a), b(_b) {}
};
multimap<int, edge> mp;
int main() {
	cin >> n >> m;
	makeSet(n);
	int a, b, len;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> len;
		mp.insert(make_pair(len, edge(a, b)));
	}
	int index = 0;
	while (index < n - 1) {
		auto p = mp.begin();
		if (find(p->second.a) != find(p->second.b)) {
			merge(p->second.a, p->second.b);
			total += p->first;
			index++;
		}
		mp.erase(p);
	}
	cout << total;
}