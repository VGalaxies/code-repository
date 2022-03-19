#include <iostream>
#include <cstring>
const int max_n = 10;
using namespace std;
bool vis[max_n];//记录某一行棋子是否有棋子摆放
char mp[max_n][max_n];
int n, k, sum;
void dfs(int x, int y)//搜索函数，注意参数的含义
{
    if (y >= k)//只有摆放了一个棋子，y才会加一
    { 
        sum++; 
        return;
    }//当棋子摆放完时，计数器加一，回溯
    for (int i = x; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (!vis[j] && mp[i][j] == '#') //棋子只能在棋盘区域
            {
                vis[j] = true;//设置第j列有棋子了
                dfs(i + 1, y + 1);//进行下一行的计算
                vis[j] = false;//递归结束后，设置第j列没有棋子了
            }
        }
    }
}
int main()
{
    while (cin >> n >> k && !(n == -1 && k == -1))
    {
        memset(vis, false, sizeof(vis));//初始化
        memset(mp, false, sizeof(mp));
        for (int i = 0; i < n; i++)//输入二维数组
            cin >> mp[i];
        sum = 0;
        dfs(0, 0);
        cout << sum << endl;
    }
    return 0;
}