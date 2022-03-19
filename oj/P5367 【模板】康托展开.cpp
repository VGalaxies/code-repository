#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;
const int MAXN = 1000010;
const int MOD = 998244353;
ll fact[MAXN] = { 1 }, P[MAXN], A[MAXN], tree[MAXN];

void init(int n) {
    int i = 1;
    while (i <= n) {
        fact[i] = i * fact[i - 1] % MOD;//别忘了取模
        i++;
    }
}

ll lowbit(ll x) { return x & -x; }
ll query(ll x)
{
    ll ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
void update(ll x, ll d)
{
    for (int i = x; i < MAXN; i += lowbit(i))
        tree[i] += d;
}

ll cantor(ll P[], int n)
{
    ll ans = 1;
    for (int i = n; i >= 1; i--)
    {
        A[i] = query(P[i]);
        update(P[i], 1);
    }
    for (int i = 1; i < n; i++)
        ans = (ans + A[i] * fact[n - i]) % MOD;
    return ans;
}


void decanter(ll x, int n)             // x为排列的排名，n为排列的长度
{
    x--;
    vector<int> rest(n, 0);
    iota(rest.begin(), rest.end(), 1); // 将rest初始化为1,2,...,n
    for (int i = 1; i <= n; ++i)
    {
        A[i] = x / fact[n - i];
        x %= fact[n - i];
    }
    for (int i = 1; i <= n; ++i)
    {
        P[i] = rest[A[i]];
        rest.erase(lower_bound(rest.begin(), rest.end(), P[i]));
    }
}

int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> P[i];
    init(n);
    ll ans = cantor(P, n);
    cout << ans;
    decanter(ans, n);
}