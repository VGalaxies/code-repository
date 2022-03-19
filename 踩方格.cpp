#include<iostream>
#include<cstring>
using namespace std;
bool visited[30][50];
int ways(int x, int y, int i)
{
	int tmp_sum = 0;//在固定的x,y,i下的方法数
	if (!i)
		return 1;//若i=0，返回1，这说明了ways(x,y,1)=3，三个方向
	visited[x][y] = true;//走了(x,y)，再更深层调用递归时，(x,y)不能走了
	if (!visited[x + 1][y])
		tmp_sum += ways(x + 1, y, i - 1);
	if (!visited[x][y - 1])
		tmp_sum += ways(x, y - 1, i - 1);
	if (!visited[x][y + 1])
		tmp_sum += ways(x, y + 1, i - 1);
	visited[x][y] = false;//★,回溯，为同层的其他递归调用做准备
	return tmp_sum;
}
int main()
{
	int n;
	cin >> n;
	memset(visited, 0, sizeof(visited));
	cout << ways(0, 25, n);
	return 0;
}