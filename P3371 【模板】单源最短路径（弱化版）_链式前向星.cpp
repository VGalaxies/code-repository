#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n, m, source;//n���㣬m����
const int maxm = 500010;//�������ֵ
const int maxn = 10010;//�������ֵ
int dist[maxn];
int vis[maxn];
int cnt;
int head[maxn];//head[i],��ʾ��iΪ���ĵ�һ�����ڱ߼������λ�ã���ţ�
int inaccessible;
struct Edge
{
	int to, w, next;//�յ㣬��Ȩ��ͬ������һ���ߵı��
}edge[maxm];//�߼�
void init()//��ʼ��
{
	for (int i = 0; i <= n; i++) 
		head[i] = -1;
	cnt = 0;
}
void add_edge(int u, int v, int w)//�ӱߣ�u��㣬v�յ㣬w��Ȩ
{
	edge[cnt].to = v; //�յ�
	edge[cnt].w = w; //Ȩֵ
	edge[cnt].next = head[u];//��uΪ�����һ���ߵı�ţ�Ҳ����������������ͬ����һ���ߵı��
	head[u] = cnt++;//������uΪ�����һ���ߵı��
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
	for (int j = head[x]; j != -1; j = edge[j].next)//������xΪ���ı� 
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
	for (int j = head[source]; j != -1; j = edge[j].next)//������sourceΪ���ı� 
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
	for (int i = 1; i <= m; i++)//����m����
	{
		cin >> u >> v >> w;
		add_edge(u, v, w);//�ӱ�
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