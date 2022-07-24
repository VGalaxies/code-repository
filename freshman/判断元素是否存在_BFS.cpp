#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int bfs(long long k, int x)
{
    long long t1, t2, t3;
    if (k == x) return 1;
    else if (k > x) return -1;

    queue<long long> q;
    q.push(k);

    while (!q.empty())
    {
        printf("%lld\n",q.front());
        t1 = q.front(); q.pop();
        t2 = t1 * 2 + 1;
        t3 = t1 * 3 + 1;
        if (t2 == x || t3 == x) return 1;
        else
        {
            if (t2 < x) q.push(t2);
            if (t3 < x) q.push(t3);
        }
    }
    return -1;
}
int main()
{
    long long k;
    int x;

    scanf("%lld,%d", &k, &x);
    int res = bfs(k, x);
    if (res == 1)printf("YES\n");
    else printf("NO\n");
    return 0;
}