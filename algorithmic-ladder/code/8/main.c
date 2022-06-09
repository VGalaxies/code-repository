#include <limits.h>
#include <stdio.h>

#define MAXN 18
#define MAXPOW 1 << MAXN
#define GET(val, offset) (val >> offset) & 1

int n, m, v, w;
long long dp[MAXN][MAXPOW];
long long weight[MAXN][MAXN];
long long val;

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      weight[i][j] = LLONG_MAX;
    }
  }

  for (int i = 0; i < MAXN; ++i) {
    for (int j = 1; j < MAXPOW; ++j) {
      dp[i][j] = LLONG_MAX;
    }
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d%d%lld", &v, &w, &val);
    weight[v - 1][w - 1] = val;
    weight[w - 1][v - 1] = val;
  }

  dp[0][1] = 0;
  for (int s = 1; s < (1 << n); ++s) {
    for (int i = 0; i < n; ++i) {
      if (GET(s, i) && dp[i][s] != LLONG_MAX) {
        for (int j = 0; j < n; ++j) {
          if (!GET(s, j) && weight[i][j] != LLONG_MAX) {
            if (dp[j][s | (1 << j)] > dp[i][s] + weight[i][j]) {
              dp[j][s | (1 << j)] = dp[i][s] + weight[i][j];
            }
          }
        }
      }
    }
  }

  long long res = LLONG_MAX;
  for (int i = 1; i < n; ++i) {
    if (res > dp[i][(1 << n) - 1]) {
      res = dp[i][(1 << n) - 1];
    }
  }
  printf("%lld\n", res);
}
