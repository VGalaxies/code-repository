#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
typedef long long ll;
const int MAXN = 100010;
ll TreeSum[MAXN << 2];
ll TreeMin[MAXN << 2];
int n;
vector<int> ans;
long double best, cur;
int ori[MAXN];
void build(int l, int r, int rt) {
    if (l == r) {
        TreeSum[rt] = TreeMin[rt] = ori[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    TreeSum[rt] = TreeSum[rt << 1] + TreeSum[rt << 1 | 1];
    TreeMin[rt] = min(TreeMin[rt << 1], TreeMin[rt << 1 | 1]);
}
ll query(int l, int r, int cl, int cr, int rt, int op) {
    if (op) {//Sum
        if (l <= cl && r >= cr)
            return TreeSum[rt];
        ll ans = 0;
        int mid = (cl + cr) >> 1;
        if (l <= mid)
            ans += query(l, r, cl, mid, rt << 1, op);
        if (r > mid)
            ans += query(l, r, mid + 1, cr, rt << 1 | 1, op);
        return ans;
    }
    else {
        if (l <= cl && r >= cr)
            return TreeMin[rt];
        ll ans = 1e10;
        int mid = (cl + cr) >> 1;
        if (l <= mid)
            ans = min(ans, query(l, r, cl, mid, rt << 1, op));
        if (r > mid)
            ans = min(ans, query(l, r, mid + 1, cr, rt << 1 | 1, op));
        return ans;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> ori[i];
    vector<int> score(ori, ori + n);
    build(1, n, 1);
    for (int i = 2; i <= n - 1; ++i) {
        cur = query(i, n, 1, n, 1, 1) - query(i, n, 1, n, 1, 0);
        cur /= n - i;
        if (cur > best) {
            best = cur;
            ans.clear();
        }
        if (cur == best)
            ans.push_back(i - 1);
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
}