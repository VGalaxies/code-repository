#include<iostream>
#include<cstring>
using namespace std;
int A, B, C;
char Moves[][10] = { "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)",  "POUR(1,2)", "POUR(2,1)" };
struct Node
{
	int a;
	int b;
	int f;//父节点
	int m;//从父节点到本结点的移动方式
}myQueue[50000];
bool visited[111][111];
int head = 0;
int tail = 1;
char result[50000][10];
Node NewStatus(Node tmp, int m)
{
	switch (m)
	{
	case 0:tmp.a = A; break;
	case 1:tmp.b = B; break;
	case 2:tmp.a = 0; break;
	case 3:tmp.b = 0; break;
	case 4:
		if (tmp.a >= B - tmp.b)
		{
			tmp.a = tmp.a - (B - tmp.b);
			tmp.b = B;
		}
		else
		{
			tmp.b = tmp.a + tmp.b;
			tmp.a = 0;//注意先后顺序！
		}
		break;
	case 5:
		if (tmp.b >= A - tmp.a)
		{
			tmp.b = tmp.b - (A - tmp.a);
			tmp.a = A;
		}
		else
		{
			tmp.a = tmp.a + tmp.b;
			tmp.b = 0;//注意先后顺序！
		}
		break;
	}
	return tmp;
}
bool Bfs()
{
	Node newStatus;
	myQueue[head].a = 0;
	myQueue[head].b = 0;
	myQueue[head].f = -1;
	myQueue[head].m = 0;
	visited[0][0] = true;
	while (head < tail)
	{
		int a_tmp = myQueue[head].a;
		int b_tmp = myQueue[head].b;
		if (a_tmp == C || b_tmp == C)
			return true;
		for (int i = 0; i < 6; ++i)
		{
			newStatus = NewStatus(myQueue[head], i);
			if (visited[newStatus.a][newStatus.b])
				continue;
			visited[newStatus.a][newStatus.b] = true;
			myQueue[tail].a = newStatus.a;
			myQueue[tail].b = newStatus.b;
			myQueue[tail].f = head;
			myQueue[tail].m = i;
			tail++;
		}
		head++;
	}
	return false;
}
int main()
{
	cin >> A >> B >> C;
	memset(visited, 0, sizeof(visited));
	if (Bfs())
	{
		int moves = 0;
		int pos = head;
		do
		{
			strcpy_s(result[moves], Moves[myQueue[pos].m]);
			pos = myQueue[pos].f;
			moves++;
		} while (pos);
		cout << moves << endl;
		for (int i = moves - 1; i >= 0; i--)
			cout << result[i] << endl;
	}
	else
		cout << "impossible" << endl;
}