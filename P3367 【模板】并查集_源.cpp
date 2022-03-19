#include<iostream>
using namespace std;
int Fa[10010];
int Rank[10010];
int N, M;
int Z;
int X, Y;
int find(int x)
{
	if (x == Fa[x])
		return x;
	else {
		Fa[x] = find(Fa[x]);  //父节点设为根节点
		return Fa[x];         //返回父节点
	}
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
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		Fa[i] = i;
		Rank[i] = 1;
	}
	for (int i = 0; i < M; ++i) {
		cin >> Z >> X >> Y;
		if (Z == 1) 
			merge(X, Y);
		else if (Z == 2) {
			if (find(X) == find(Y))
				cout << 'Y';
			else
				cout << 'N';
			cout << endl;
		}
	}
}