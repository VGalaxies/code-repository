#include<iostream>
using namespace std;
const int MAXN = 100010;
// L: ���������ڵ��ţ�R�����������ڵ��ţ�N���ýڵ㴢��������ֵĴ���
// val���ýڵ㴢�������size���Ըýڵ�Ϊ���ڵ�������Ľڵ���Ŀ����������С��
int L[MAXN], R[MAXN], N[MAXN], val[MAXN], Size[MAXN], cnt = 1;//cntΪ�ڵ��ţ���1��ʼ

void insert(int v, int pos = 1) // ����
{
    Size[pos]++; // ����С+1
    if (N[pos] == 0 && L[pos] == 0 && R[pos] == 0) // �սڵ�
    {
        val[pos] = v;
        N[pos] = 1;
    }
    else if (v < val[pos]) // ��������
    {
        if (L[pos] == 0) // ���Ӧ�������ѣ�����������ڵ㣬�򴴽�һ���½ڵ�
            L[pos] = ++cnt;
        insert(v, L[pos]);
    }
    else if (v > val[pos]) // ��������
    {
        if (R[pos] == 0)
            R[pos] = ++cnt;
        insert(v, R[pos]);
    }
    else // �Ѿ�����ֵ��ͬ�Ľڵ�
        N[pos]++;
}
void remove(int v, int pos = 1) // ɾ��
{
    Size[pos]--; // ����С-1
    if (v < val[pos])
        remove(v, L[pos]);
    else if (v > val[pos])
        remove(v, R[pos]);
    else
        N[pos]--;
}
int countl(int v, int pos = 1) // ���ĳ��С�����ĸ���
{
    if (v < val[pos])
        return L[pos] ? countl(v, L[pos]) : 0;
    else if (v > val[pos])
        return Size[L[pos]] + N[pos] + (R[pos] ? countl(v, R[pos]) : 0);
    else
        return Size[L[pos]];
}
int countg(int v, int pos = 1) // ���ĳ��������ĸ���
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
int kth(int k, int pos = 1) // ��ָ����������
{
    if (Size[L[pos]] + 1 > k) // ����������������������Ϊk����
        return kth(k, L[pos]);
    else if (Size[L[pos]] + N[pos] < k)  // �����ң�����������������Ϊk - size[L[pos]] - N[pos]����
        return kth(k - Size[L[pos]] - N[pos], R[pos]);
    else
        return val[pos];
}
int pre(int v) // ��ǰ��
{
    int r = countl(v);
    return kth(r);
}
int suc(int v) // ����
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