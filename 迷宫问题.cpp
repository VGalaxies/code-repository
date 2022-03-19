#include<iostream>
#include<cstring>
using namespace std;
int maze[5][5];
bool visited[5][5];
struct MAP
{
	int r, c;
	int f;
}queue[26];
MAP* head = queue;
MAP* tail = queue + 1;
MAP result[26];

int main()
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> maze[i][j];
	memset(visited, false, sizeof(visited));
	visited[0][0] = true;
	queue[0].r = 0;
	queue[0].c = 0;
	while (head < tail)
	{
		int i = head->r;
		int j = head->c;
		int index = head - queue;
		if (i == 4 && j == 4)
			break;
		else
			head++;
		if (i > 0&&!visited[i-1][j]&&!maze[i-1][j])
		{
			visited[i - 1][j] = true;
			tail->r = i - 1;
			tail->c = j;
			tail->f = index;
			tail++;
		}
		if (i < 4 && !visited[i + 1][j] && !maze[i + 1][j])
		{
			visited[i + 1][j] = true;
			tail->r = i + 1;
			tail->c = j;
			tail->f = index;
			tail++;
		}
		if (j > 0 && !visited[i][j-1] && !maze[i][j-1])
		{
			visited[i][j - 1] = true;
			tail->r = i;
			tail->c = j-1;
			tail->f = index;
			tail++;
		}
		if (j < 4 && !visited[i][j + 1] && !maze[i][j + 1])
		{
			visited[i][j + 1] = true;
			tail->r = i;
			tail->c = j + 1;
			tail->f = index;
			tail++;
		}
	}
	int count = 0;
	while ((head - queue) != 0)
	{
		int gap = (head - queue) - head->f;
		result[count].c = head->c;
		result[count].r = head->r;
		head = head - gap;
		count++;
	}
	for (int i = count; i >= 0; --i)
		cout << "("<< result[i].r << ", " << result[i].c <<")" << endl;
	return 0;
}