#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAXN 15010
#define MAXM 32010
#define lowbit(x) ((x) & (-x))
// ��״����
int tree[MAXM], ans[MAXN];
void update(int i, int x)
{
    for (; i <= MAXM; i += lowbit(i))
        tree[i] += x;
}
int query(int n)
{
    int ans = 0;
    for (; n; n -= lowbit(n))
        ans += tree[n];
    return ans;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%*d", &x); // �Ѿ��ź����ˣ�y������Բ�Ҫ��
        ans[query(x + 1)]++; // ͳ��
        update(x + 1, 1); // ���£�ע�������ж�Ҫ+1
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}