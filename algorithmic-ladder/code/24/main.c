#include <stdio.h>
#include <string.h>

#define MAXN 5005
#define MAXK 5005
#define MOD 1000000007

int n, k, t;
// n start at 1, k start at 0
int ans[MAXN][MAXK];
// k start at 1
int a[MAXK + 1];

int lowbit(int x) { return x & (-x); }

void updata(int i, int k) {
  while (i < MAXK + 1) {
    a[i] = (a[i] + k) % MOD;
    i += lowbit(i);
  }
}

int getsum(int i) {
  int res = 0;
  while (i > 0) {
    res = (res + a[i]) % MOD;
    i -= lowbit(i);
  }
  return res;
}

int range(int l, int r) {
  int res = getsum(r) - getsum(l - 1);
  if (res < 0) {
    res += MOD;
  }
  return res % MOD;
}

void print_tree() {
  for (int i = 1; i < MAXK + 1; ++i)
    printf("%d ", a[i]);

  printf("\n");

  for (int i = 1; i < MAXK + 1; ++i)
    printf("%d ", range(i, i));

  printf("\n");
  printf("\n");
}

void print_ans() {
  for (int i = 1; i < MAXN; ++i) {
    for (int j = 0; j < MAXK; ++j) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void init() {
  ans[1][0] = 1;

  for (int i = 2; i < MAXN; ++i) {
    memset(a, 0, sizeof a);
    for (int j = 0; j < MAXK; ++j) {
      updata(j + 1, ans[i - 1][j]);
    }
    /* print_tree(); */
    for (int j = 0; j < MAXK; ++j) {
      int l = (j - (i - 1)) >= 0 ? (j - (i - 1)) : 0;
      int r = j;
      ans[i][j] = range(l + 1, r + 1);
    }
  }
}

int main() {
  init();
  /* print_ans(); */

  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d%d", &n, &k);
    printf("%d\n", ans[n][k]);
  }
}
