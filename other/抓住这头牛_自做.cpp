#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, K;
bool visited[100010];
struct Node
{
	int index;
	int step;
	Node(int x, int y):index(x), step(y) { }
};
queue<Node> q;
int main()
{
	cin >> N >> K;
	memset(visited, false, sizeof(visited));
	visited[N] = true;
	q.push(Node(N, 0));
	while (!q.empty())//
	{
		Node tmp = q.front();//
		if (tmp.index == K)
		{
			cout << tmp.step << endl;//Òª¼Ó»»ÐÐ·û
			return 0;
		}
		else
		{
			if (tmp.index - 1 >= 0 && !visited[tmp.index - 1])
			{
				visited[tmp.index - 1] = true;
				q.push(Node(tmp.index - 1, tmp.step + 1));
			}
			if (tmp.index + 1 <= 100000 && !visited[tmp.index + 1])
			{
				visited[tmp.index + 1] = true;
				q.push(Node(tmp.index + 1, tmp.step + 1));
			}		
			if (tmp.index * 2 <= 100000 && !visited[tmp.index * 2])
			{
				visited[tmp.index * 2] = true;
				q.push(Node(tmp.index * 2, tmp.step + 1));
			}
			q.pop();
		}
	}
	return 0;
}