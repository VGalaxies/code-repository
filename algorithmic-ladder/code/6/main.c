#include <limits.h>
#include <math.h>
#include <stdio.h>

#define MAXN 10005
int n, t, ans;
int page[MAXN];

int check(int speed) {
  int total_time = 0;
  for (int i = 0; i < n; ++i) {
    total_time += (int)ceil((double)page[i] / speed);
  }

  if (total_time > t) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int max_page = INT_MIN;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &page[i]);
    max_page = (max_page < page[i]) ? page[i] : max_page;
  }

  int l = 1, r = max_page, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (!check(mid)) {
      l = mid + 1;
      ans = l;
    } else {
      r = mid - 1;
      ans = l;
    }
  }

  printf("%d\n", ans);
}
