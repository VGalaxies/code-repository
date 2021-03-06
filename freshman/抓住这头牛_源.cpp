#include <iostream> 
#include <cstring> 
#include <queue> 
using namespace std;
int N, K;
const int MAXN = 100000;
int visited[MAXN + 10];	//判重标记,visited[i] = true表示i已经扩展过
struct Step {
	int x;	//位置
	int steps;	//到达x所需的步数
	Step(int xx, int s) :x(xx), steps(s) { }
};
queue<Step> q;	//队列,即Open表
int main()	
{
	cin >> N >> K; 
	memset(visited, 0, sizeof(visited)); 
	q.push(Step(N, 0));
	visited[N] = 1;
	while (!q.empty()) 
	{
		Step s = q.front();
		if (s.x == K) 
		{ //找到目标
			cout << s.steps << endl;
			return 0;
		}
		else 
		{
			if (s.x - 1 >= 0 && !visited[s.x - 1]) 
			{
				q.push(Step(s.x - 1, s.steps + 1)); visited[s.x - 1] = 1;
			}
			if (s.x + 1 <= MAXN && !visited[s.x + 1]) 
			{
				q.push(Step(s.x + 1, s.steps + 1)); visited[s.x + 1] = 1;
			}
			if (s.x * 2 <= MAXN && !visited[s.x * 2]) 
			{
				q.push(Step(s.x * 2, s.steps + 1)); visited[s.x * 2] = 1;
			}
			q.pop();
		}
	}
	return 0;
}


