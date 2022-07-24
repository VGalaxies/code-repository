#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
int main()
{
    int n, k, m, l, r, t;
    scanf("%d%d%d", &n, &k, &m);
    std::vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);//也可以从数组用地址复制，可能会快一些
    for (t = n, l = 0, r = n; t;)//l、r 分别是上一个顺、逆时针删除元素的位置
    {
        l = (l + k - 1) % t, r = (r + t - m % t) % t, t -= 2;//顺时针移 l-1，逆时针移 m （因为删除后 l 和 r 都指向后一个元素）
        if (l == r)
            break;
        printf("%d %d ", v[l], v[r]);
        if (t)
            v.erase(v.begin() + l), v.erase(v.begin() + (r -= r > l ? 1 : 0)), l -= l > r ? 1 : 0;
        //删除时要注意顺时针删除的元素下标 l 较小时逆时针删除的元素下标 r 要 -1
        //若逆时针删除的元素下标较小，则指向顺时针删除元素后一个元素的 l 也要 -1
    }
    if (l == r)
        printf("%d\n", v[l]);
    return 0;
}