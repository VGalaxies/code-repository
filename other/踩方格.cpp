#include<iostream>
#include<cstring>
using namespace std;
bool visited[30][50];
int ways(int x, int y, int i)
{
	int tmp_sum = 0;//�ڹ̶���x,y,i�µķ�����
	if (!i)
		return 1;//��i=0������1����˵����ways(x,y,1)=3����������
	visited[x][y] = true;//����(x,y)���ٸ������õݹ�ʱ��(x,y)��������
	if (!visited[x + 1][y])
		tmp_sum += ways(x + 1, y, i - 1);
	if (!visited[x][y - 1])
		tmp_sum += ways(x, y - 1, i - 1);
	if (!visited[x][y + 1])
		tmp_sum += ways(x, y + 1, i - 1);
	visited[x][y] = false;//��,���ݣ�Ϊͬ��������ݹ������׼��
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