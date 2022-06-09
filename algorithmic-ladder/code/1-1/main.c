#include <stdio.h>

int n, now, k, m, know, mnow;
int a[100005];

int lowbit(int x) { return x & (-x); }

#define Log(format, ...)                                                       \
  do {                                                                         \
    printf("\33[1;35m[%s, %d, %s] " format "\33[0m\n", __FILE__, __LINE__,     \
           __func__, ##__VA_ARGS__);                                           \
  } while (0)

void updata(int i, int k) {
  while (i <= n) {
    a[i] += k;
    i += lowbit(i);
  }
}

int getsum(int i) {
  int res = 0;
  while (i > 0) {
    res += a[i];
    i -= lowbit(i);
  }
  return res;
}

int getid(int x) {
  if (x == 0)
    x = now;
  int l = 0, r = n, m;
  while (l + 1 < r) {
    m = (l + r) >> 1;
    if (getsum(m) >= x)
      r = m;
    else
      l = m;
  }
  return r;
}

void print() {
  for (int i = 1; i <= n; ++i)
    printf("%d ", a[i]);

  printf("\n");

  for (int i = 1; i <= n; ++i)
    printf("%d ", getsum(i) - getsum(i - 1));

  printf("\n");
}

int main() {
  scanf("%d%d%d", &n, &k, &m);

  now = n;
  for (int i = 1; i <= n; i++)
    updata(i, 1);
  
  // print();

  int know = 0, mnow = n;

  // iterate
  while (now) {
    int ktmp = (getsum(know) + (k % now)) % now;
    int mtmp = (getsum(mnow) + now + 1 - (m % now)) % now;

    know = getid(ktmp);
    mnow = getid(mtmp);

    Log("know = getid(%d), mnow = getid(%d)", ktmp, mtmp);

    if (know == mnow) {
      Log("%d", know);
      return 0;
    }

    Log("%d %d", know, mnow);
    now -= 2;

    updata(know, -1);
    updata(mnow, -1);

    // print();
  }

  return 0;
}
