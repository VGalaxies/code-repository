#include <algorithm>
#include <iostream>
using namespace std;
int A[8], cnt, dp[8][12][2]; 
// ��ʾpos+1λ����ǰһλΪlast,��limit�����£�����Ҫ������ĸ���
int dfs(int pos, int last, bool limit)
{
    int ans = 0;
    if (pos == cnt)
        return 1; // �����յ�
    if (dp[pos][last][limit] != -1)
        return dp[pos][last][limit];
    for (int v = 0; v <= (limit ? A[pos] : 9); ++v) // �����Ƿ�limit����ѭ���Ͻ�
    {
        if (last == 6 && v == 2 || v == 4) // �������Ϸ���
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
    memset(dp, -1, sizeof(dp)); // ��ʼ��dp����Ϊ-1
    while (x)
        A[cnt++] = x % 10, x /= 10;
    reverse(A, A + cnt);
    return dfs(0, 11, true);    // ��lastΪ11��ʾ��������һλ
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