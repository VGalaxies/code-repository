#include <stdio.h>

#define MIN(x, y) (x) < (y) ? (x) : (y)
#define MAXN 300005

int n;
int speed[MAXN][2];

long long ans;

long long search(int x, int y, int another, int time, int flag) {
  if (time == 2 * n) {
    return 0;
  }

  if (flag == 0) {
    // →
    long long res_1 = 0;
    // ↑ or ↓
    long long res_2 = 0;

    for (int i = x; i < n; ++i) {
      res_1 += (time + i - x) * speed[i][y];
    }
    for (int i = n - 1; i >= another; --i) {
      res_1 += (time + n - x + (n - 1) - i) * speed[i][!y];
    }

    if (y == 0) {
      res_2 = time * speed[x][y] + search(x, 1, x + 1, time + 1, 2);
    } else {
      res_2 = time * speed[x][y] + search(x, 0, x + 1, time + 1, 1);
    }

    return MIN(res_1, res_2);
  } else if (flag == 1) {
    return time * speed[x][y] + search(x + 1, 0, x + 1, time + 1, 0);
  } else {
    return time * speed[x][y] + search(x + 1, 1, x + 1, time + 1, 0);
  }

}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &speed[i][0]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &speed[i][1]);
  }
  // flag 0 for →
  // flag 1 for ↑
  // flag 2 for ↓
  ans = search(0, 0, 0, 0, 0);

  printf("%lld\n", ans);
}
