#include <algorithm>
#include <iostream>
using namespace std;
int A[8], cnt, dp[8][12][2]; 
// 表示pos+1位数，前一位为last,在limit条件下，符合要求的数的个数
int dfs(int pos, int last, bool limit)
{
    int ans = 0;
    if (pos == cnt)
        return 1; // 搜索终点
    if (dp[pos][last][limit] != -1)
        return dp[pos][last][limit];
    for (int v = 0; v <= (limit ? A[pos] : 9); ++v) // 根据是否limit决定循环上界
    {
        if (last == 6 && v == 2 || v == 4) // 舍弃不合法解
            continue;
        ans += dfs(pos + 1, v, limit && v == A[pos]);
    }
    dp[pos][last][limit] = ans;
    return ans;
}
int f(int x)
{
    cnt = 0;
    memset(A, 0, sizeof(A));
    memset(dp, -1, sizeof(dp)); // 初始化dp数组为-1
    while (x)
        A[cnt++] = x % 10, x /= 10;
    reverse(A, A + cnt);
    return dfs(0, 11, true);    // 用last为11表示不存在上一位
}
int main()
{
    ios::sync_with_stdio(false);
    int x, y;
    while (cin >> x >> y && x && y)
    {
        int l = f(x - 1);
        int r = f(y);
        cout << r - l << endl;
    }
    return 0;
}