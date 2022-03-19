#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 200010;
long long score[MAXN << 2];
void push_up(int rt) {     //向上更新
    score[rt] = max(score[rt << 1], score[rt << 1 | 1]);
}
void build(int l, int r, int rt) {            //用满二叉树建树
    if (l == r) {                                   //叶子结点，赋值
        cin >> score[rt];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);                                  //向上更新区间和
}
void update(int a, long long c, int l, int r, int rt) {//单点更新
    if (l == r && l == a) {
        score[rt] = c;
        return;
    }
    int mid = (l + r) >> 1;//分成两半，继续深入
    if (a <= mid) 
        update(a, c, l, mid, rt << 1);        
    if (a > mid) 
        update(a, c, mid + 1, r, rt << 1 | 1);
    push_up(rt);//向上更新
}
long long query(int a, int b, int l, int r, int rt) {       //区间最值
    if (a <= l && b >= r) 
        return score[rt];
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (a <= mid)
        ans = max(ans, query(a, b, l, mid, rt << 1));
    if (b > mid)
        ans = max(ans, query(a, b, mid + 1, r, rt << 1 | 1));
    return ans;
}
int main(void) {
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        memset(score, 0, sizeof(score));
        build(1, n, 1);
        while (m--) {
            char str[2];
            int a, b; long long c;
            cin >> str;
            if (str[0] == 'U') {
                cin >> a >> c;
                update(a, c, 1, n, 1);
            }
            else {
                cin >> a >> b;
                printf("%lld\n", query(a, b, 1, n, 1));
            }
        }
    }
}