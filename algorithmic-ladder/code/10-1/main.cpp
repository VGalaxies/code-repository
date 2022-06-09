#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pin;

const int N = 3e5 + 5;
const ll inf = (ll)1 << 60;

int n;
ll a[2][N], sum[N], xi[2][N], yi[2][N], sumx[N], sumy[N];
bool mark[2][N];

template <typename T> inline void read(T &X) {
  X = 0;
  char ch = 0;
  T op = 1;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-')
      op = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    X = (X << 3) + (X << 1) + ch - 48;
  X *= op;
}

inline void chkMin(ll &x, ll y) {
  if (y < x)
    x = y;
}

inline pin getNxt(pin now) {
#define x first
#define y second

  pin res = now;
  if (res.x == 0) {
    if (res.y % 2 == 1)
      return pin(1, res.y);
    else
      return pin(0, res.y + 1);
  } else {
    if (res.y % 2 == 0)
      return pin(0, res.y);
    else
      return pin(1, res.y + 1);
  }

#undef x
#undef y
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++)
    xi[0][i] = yi[1][i] = i - 1, xi[1][i] = yi[0][i] = 2 * n - i;
  for (int i = 0; i <= 1; i++) {
    for (int j = 1; j <= n; j++) {
      read(a[i][j]);
      sum[j] += a[i][j];
      sumx[j] += a[i][j] * xi[i][j];
      sumy[j] += a[i][j] * yi[i][j];
    }
  }
  for (int j = 1, i = 1; i <= n; i++, j ^= 1) {
    sum[i] += sum[i - 1];
    sumx[i] += sumx[i - 1];
    sumy[i] += sumy[i - 1];
    mark[j][i] = 1;
  }

  ll ans = inf, res = 0LL;
  pin now = pin(0, 1);
  for (int i = 0; i < 2 * n; i++, now = getNxt(now)) {
#define x first
#define y second

    res += 1LL * i * a[now.x][now.y];
    if (mark[now.x][now.y]) {
      if (now.x == 0)
        chkMin(ans, res + (sumx[n] - sumx[now.y]) -
                        (xi[0][now.y + 1] - i - 1) * (sum[n] - sum[now.y]));
      else
        chkMin(ans, res + (sumy[n] - sumy[now.y]) -
                        (yi[1][now.y + 1] - i - 1) * (sum[n] - sum[now.y]));
    }

#undef x
#undef y
  }
  chkMin(ans, res);
  chkMin(ans, sumx[n]);

  printf("%lld\n", ans);
  return 0;
}
