#include <algorithm>
#include <cstdio>

#define MAXN 50005

struct Cable {
  int x;
  int y;
  int val;
} cable[MAXN];

int x, y, val;
int n, ans;

int to_left[MAXN];
int to_right[MAXN];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &val);
    cable[i] = {x, y, val};
  }
  std::sort(cable, cable + n, [](Cable v, Cable w) { return v.y > w.y; });

  to_left[0] = cable[0].val;
  to_right[0] = cable[0].val;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (cable[j].x > cable[i].x) {
        to_left[i] = std::max(to_left[i], to_right[j] + cable[i].val);
        ans = std::max(ans, to_left[i]);
      }
    }
    for (int j = 0; j < i; ++j) {
      if (cable[j].x < cable[i].x) {
        to_right[i] = std::max(to_right[i], to_left[j] + cable[i].val);
        ans = std::max(ans, to_right[i]);
      }
    }
  }

  printf("%d\n", ans);
}
