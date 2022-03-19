#include<iostream>
#include<cstring>
using namespace std;
int p;
int q;
bool ori[10][10];
char trans[10] = { 0,'A','B','C','D','E','F','G','H','I'};
int dq[8] = { -2,-2,-1,-1,1,1,2,2 };
int dp[8] = { -1,1,-2,2,-2,2,-1,1 };
int cases;
struct Node
{
	char q;
	int p;
}path[50];
bool judge = false;
void Dfs(int i, int j,int num)
{
	path[num].q = trans[i];//可以换为path[num].q = i - 1 + 'A';
	path[num].p = j;
	if (num == p * q)
		judge = true;
	for (int k = 0; k < 8; ++k)
	{
		int d_q = i + dq[k];
		int d_p = j + dp[k];
		if (d_q >= 1 && d_q <= q && d_p >= 1 && d_p <= p && !judge && !ori[d_q][d_p])
		{
			ori[d_q][d_p] = true;
			Dfs(d_q, d_p, num + 1);
			ori[d_q][d_p] = false;//执行到这一语句，说明Dfs(d_q, d_p, num + 1)并未让judge为true（否则就结束递归了），需要回溯，尝试循环中下一种跳法
		}
	}
	
}
int main()
{
	cin >> cases;
	for (int s = 1; s <= cases; ++s)
	{
		cin >> p >> q;
		memset(ori, false, sizeof(ori));
		memset(path, 0, sizeof(path));
		judge = false;
		ori[1][1] = true;
		Dfs(1, 1, 1);
		cout << "Scenario #" << s << ":" << endl;
		if (judge)
		{
			for (int i = 1; i <= p * q; ++i)
				cout << path[i].q << path[i].p;
		}
		else
			cout << "impossible";
		cout << endl;
		cout << endl;
	}
	return 0;
}