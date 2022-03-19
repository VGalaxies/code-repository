#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n, m, source;//n个点，m条边
const int maxm = 500010;//边数最大值
const int maxn = 10010;//点数最大值
int dist[maxn];
int vis[maxn];
int cnt;
int head[maxn];//head[i],表示以i为起点的第一条边在边集数组的位置（编号）
int inaccessible;
struct Edge
{
	int to, w, next;//终点，边权，同起点的上一条边的编号
}edge[maxm];//边集
void init()//初始化
{
	for (int i = 0; i <= n; i++) 
		head[i] = -1;
	cnt = 0;
}
void add_edge(int u, int v, int w)//加边，u起点，v终点，w边权
{
	edge[cnt].to = v; //终点
	edge[cnt].w = w; //权值
	edge[cnt].next = head[u];//以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
	head[u] = cnt++;//更新以u为起点上一条边的编号
}
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
	else {
		inaccessible++;
	}
}
void UpdateDist(int x) {
	for (int j = head[x]; j != -1; j = edge[j].next)//遍历以x为起点的边 
	{
		if (edge[j].w > 0 && dist[edge[j].to] < 0)
			dist[edge[j].to] = edge[j].w + dist[x];
		else if (edge[j].w > 0 && dist[edge[j].to] > 0)
			dist[edge[j].to] = min(edge[j].w + dist[x], dist[edge[j].to]);
	}
}
void Dijkstra() {
	vis[source] = true;
	q.push_back(source);
	for (int j = head[source]; j != -1; j = edge[j].next)//遍历以source为起点的边 
	{
		if (edge[j].w > 0 && dist[edge[j].to] < 0)
			dist[edge[j].to] = edge[j].w;
		else if (edge[j].w > 0 && dist[edge[j].to] > 0)
			dist[edge[j].to] = min(dist[edge[j].to], edge[j].w);
	}
	while (q.size() + inaccessible != n) {
		FindMinDist();
		UpdateDist(q.back());
	}
}
int main() {
	cin >> n >> m >> source;
	int u, v, w;
	memset(dist, -1, sizeof(dist));
	init();
	for (int i = 1; i <= m; i++)//输入m条边
	{
		cin >> u >> v >> w;
		add_edge(u, v, w);//加边
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