/*
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。
输入
标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。
输出
对于每组测试数据，输出N的划分数。

基本思想：https://www.cnblogs.com/konjak/p/6004018.html
f[i][j]表示划分 i 后的每个数不大于 j 的划分数。
分情况讨论：
划分中每个数都小于 j，相当于每个数不大于 j- 1, 故划分数为 f[i][j-1]
或划分中至少有一个数为 j. 相当于把剩下的 i-j 进行划分，每个数不大于j， 划分数为 f[i-j][j]。
*/
#include<iostream>
using namespace std;

int f[55][55];

int main()
{
    int n;
    while (cin>>n)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][1] = 1;
            for (int j = 2; j <= n; j++)
            {
                if (i < j)
                    f[i][j] = f[i][i];
                if (i == j) 
                    f[i][j] = f[i][j - 1] + 1;
                if (i > j) 
                    f[i][j] = f[i][j - 1] + f[i - j][j];
            }
        }
        cout << f[n][n] << endl;
    }
    return 0;
}