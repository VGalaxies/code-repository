/*https://www.cnblogs.com/konjak/p/5950919.html
题意：问把整数N分成K份的分法数。（与“放苹果”不同，在这题不可以有一份为空，但可以类比）
解法：f[i][j]表示把i分成j份的方案数。
f[i][j]=f[i-1][j-1]（新开一份，放1）
而i≥j时，f[i][j]=f[i-1][j-1]+f[i-j][j]（不新开一份时的方案数与每份中都少放1的方案数相同）

一种更好的解释——方法可以分为两类：
1、n 份中不包含 1 的分法，为保证每份都 >= 2，可以先拿出 k 个 1 分到每一份，
然后再把剩下的 n- k 分成 k 份即可，分法有: dp[n-k][k]

2、n 份中至少有一份为 1 的分法，可以先那出一个 1 作为单独的1份，
剩下的 n- 1 再分成 k- 1 份即可，分法有：dp[n-1][k-1]
*/

#include<iostream>
using namespace std;

int f[210][10];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        f[i][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= k; j++)
            if (j <= i)
                f[i][j] = f[i - 1][j - 1] + f[i - j][j];
    cout << f[n][k] << endl;
    return 0;
}