#include<cstdio>
#include<iostream>
using namespace std;
int a[500010];
int t[500010];
int n;
long long int ans = 0;
void merge(int ll, int rr) {
    //����ҿ�
    //t������ʱ�������İ汾
    if (rr - ll <= 1) 
        return;
    int mid = ll + ((rr - ll) >> 1);
    merge(ll, mid);
    merge(mid, rr);
    int p = ll, q = mid, s = ll;
    while (s < rr) {
        if (p >= mid || (q < rr && a[p] > a[q])) {
            t[s++] = a[q++];
            ans += (long long int)(mid - p);//������Ҫ������
        }
        else
            t[s++] = a[p++];
    }
    for (int i = ll; i < rr; ++i) 
        a[i] = t[i];
}
//�ؼ�������һ���Դ������飬������ÿ�εݹ����ʱ�������Ա���������ν�����������
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    merge(0, n);
    cout << ans;
}