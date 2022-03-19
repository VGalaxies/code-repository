#include<iostream>
using namespace std;
const int MAXN = 100010;
// L: 左子树根节点编号，R：右子树根节点编号，N：该节点储存的数出现的次数
// val：该节点储存的数，size：以该节点为根节点的子树的节点数目（即子树大小）
int L[MAXN], R[MAXN], N[MAXN], val[MAXN], Size[MAXN], cnt = 1;//cnt为节点编号，从1开始

void insert(int v, int pos = 1) // 插入
{
    Size[pos]++; // 树大小+1
    if (N[pos] == 0 && L[pos] == 0 && R[pos] == 0) // 空节点
    {
        val[pos] = v;
        N[pos] = 1;
    }
    else if (v < val[pos]) // 向左搜索
    {
        if (L[pos] == 0) // 如果应该向左搜，但不存在左节点，则创建一个新节点
            L[pos] = ++cnt;
        insert(v, L[pos]);
    }
    else if (v > val[pos]) // 向右搜索
    {
        if (R[pos] == 0)
            R[pos] = ++cnt;
        insert(v, R[pos]);
    }
    else // 已经存在值相同的节点
        N[pos]++;
}
void remove(int v, int pos = 1) // 删除
{
    Size[pos]--; // 树大小-1
    if (v < val[pos])
        remove(v, L[pos]);
    else if (v > val[pos])
        remove(v, R[pos]);
    else
        N[pos]--;
}
int countl(int v, int pos = 1) // 求比某数小的数的个数
{
    if (v < val[pos])
        return L[pos] ? countl(v, L[pos]) : 0;
    else if (v > val[pos])
        return Size[L[pos]] + N[pos] + (R[pos] ? countl(v, R[pos]) : 0);
    else
        return Size[L[pos]];
}
int countg(int v, int pos = 1) // 求比某数大的数的个数
{
    if (v > val[pos])
        return R[pos] ? countg(v, R[pos]) : 0;
    else if (v < val[pos])
        return Size[R[pos]] + N[pos] + (L[pos] ? countg(v, L[pos]) : 0);
    else
        return Size[R[pos]];
}
int Rank(int v)
{
    return countl(v) + 1;
}
int kth(int k, int pos = 1) // 求指定排名的数
{
    if (Size[L[pos]] + 1 > k) // 答案在左，在左子树中找排名为k的数
        return kth(k, L[pos]);
    else if (Size[L[pos]] + N[pos] < k)  // 答案在右，在右子树中找排名为k - size[L[pos]] - N[pos]的数
        return kth(k - Size[L[pos]] - N[pos], R[pos]);
    else
        return val[pos];
}
int pre(int v) // 求前驱
{
    int r = countl(v);
    return kth(r);
}
int suc(int v) // 求后继
{
    int r = Size[1] - countg(v) + 1;
    return kth(r);
}
int n, op, x;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> op >> x;
        switch (op)
        {
        case 1:insert(x);break;
        case 2:remove(x);break;
        case 3:cout << Rank(x) << endl;break;
        case 4:cout << kth(x) << endl;break;
        case 5:cout << pre(x) << endl;break;
        case 6:cout << suc(x) << endl; break;
        }
    }
}