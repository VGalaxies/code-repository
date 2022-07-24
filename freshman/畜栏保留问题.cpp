#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n;
struct Node
{
	int st;
	int ed;
	int index;
	bool operator<(const Node& a)const {
		return st < a.st;}
}ori[51111];
struct Stall
{
	int ed;
	int index;
	bool operator<(const Stall& a)const {
		return ed > a.ed;//优先队列
	}
	Stall(int a,int b):ed(a),index(b){}
};//后面不能加pos[51111]
int pos[51111];
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> ori[i].st >> ori[i].ed;
		ori[i].index = i;
	}	
	sort(ori, ori + n);
	priority_queue<Stall> q;
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (q.empty())
		{
			index++;
			q.push(Stall(ori[i].ed, index));
			pos[ori[i].index] = index;
		}
		else
		{
			Stall tmp = q.top();
			if (tmp.ed < ori[i].st)
			{
				pos[ori[i].index] = tmp.index;
				q.pop();//丢了
				q.push(Stall(ori[i].ed, index));
			}
			else
			{
				index++;
				pos[ori[i].index] = index;
				q.push(Stall(ori[i].ed, index));
			}
		}
	}
	cout << index <<endl;
	for (int i = 0; i < n; ++i)
		cout << pos[i] << endl;
	return 0;
}