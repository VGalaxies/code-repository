#include <algorithm>
#include <climits>
#include <cstdio>

#define MAXN 100005

int n;
int a[MAXN], dp[MAXN];

void solve() {
  int ans{};
  for (int i = 0; i < n; ++i) {
    dp[i] = 0;
  }

  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] <= a[i]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
        ans = std::max(ans, dp[i]);
      }
    }
  }

  printf("%d\n", ans);
}

void solve_faster() {
  int ans{};
  for (int i = 0; i < n; ++i) {
    dp[i] = INT_MAX;
  }

  for (int i = 0; i < n; ++i) {
    *std::upper_bound(dp, dp + n, a[i]) = a[i];
  }

  while (dp[ans] != INT_MAX) {
    ans++;
  }

  printf("%d\n", ans);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  solve();
  solve_faster();
}
