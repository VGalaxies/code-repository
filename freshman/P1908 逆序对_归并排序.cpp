#include<cstdio>
#include<iostream>
using namespace std;
int a[500010];
int t[500010];
int n;
long long int ans = 0;
void merge(int ll, int rr) {
    //左闭右开
    //t数组临时存放有序的版本
    if (rr - ll <= 1) 
        return;
    int mid = ll + ((rr - ll) >> 1);
    merge(ll, mid);
    merge(mid, rr);
    int p = ll, q = mid, s = ll;
    while (s < rr) {
        if (p >= mid || (q < rr && a[p] > a[q])) {
            t[s++] = a[q++];
            ans += (long long int)(mid - p);//两个都要加括号
        }
        else
            t[s++] = a[p++];
    }
    for (int i = ll; i < rr; ++i) 
        a[i] = t[i];
}
//关键点在于一次性创建数组，避免在每次递归调用时创建，以避免对象的无谓构造和析构。
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    merge(0, n);
    cout << ans;
}