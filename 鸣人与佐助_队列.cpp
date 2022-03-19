/*Lucky_Glass*/
#include<cstdio>
#include<queue>
using namespace std;
struct POINT
{
    int x, y, tot, T;
} point;
queue<POINT> que;
int main()
{
    bool walked[205][205][15] = {};
    int r, c, T, F[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    scanf("%d%d%d", &r, &c, &T);
    char maze[205][205] = {};
    for (int i = 0; i < r; i++)
    {
        scanf("%s", maze[i]);
        for (int j = 0; j < c; j++)
            if (maze[i][j] == '@')
            {
                point.x = i; point.y = j;
                point.tot = 0; point.T = T;
            }
    }
    que.push(point);
    while (!que.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            point.x = que.front().x + F[i][0];
            point.y = que.front().y + F[i][1];
            point.tot = que.front().tot + 1;
            point.T = que.front().T;
            if (point.x < 0 || point.x >= r || point.y < 0 || point.y >= c || walked[point.x][point.y][point.T]) continue;
            if (maze[point.x][point.y] == '#')
                if (point.T) point.T--;
                else continue;
            if (maze[point.x][point.y] == '+') { printf("%d\n", point.tot); return 0; }
            walked[point.x][point.y][point.T] = true;
            que.push(point);
        }
        que.pop();
    }
    printf("-1\n");
    return 0;
}