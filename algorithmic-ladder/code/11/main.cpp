#include <cstdio>

#define MAXN 3
#define MOD 1000000007

long long n;
int l, r;
int a, b, c;
int ans;

struct Matrix {
  long long arr[MAXN][MAXN]{};
  void build() { // identity Matrix
    for (int i = 0; i < MAXN; ++i)
      arr[i][i] = 1;
  }
  friend Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix re;
    for (int i = 0; i < MAXN; ++i) {
      for (int j = 0; j < MAXN; ++j) {
        for (int k = 0; k < MAXN; ++k) {
          re.arr[i][k] = (re.arr[i][k] + a.arr[i][j] * b.arr[j][k]) % MOD;
        }
      }
    }
    return re;
  }
} ori, res;

Matrix quickpow(Matrix b, long long q) {
  Matrix ans;
  ans.build();
  do {
    if (q & 1) {
      ans = ans * b;
    }
    b = b * b;
    q >>= 1;
  } while (q);
  return ans;
}

int main() {
  scanf("%lld%d%d", &n, &l, &r);
  for (int i = l; i <= r; ++i) {
    if (i % 3 == 0) {
      a++;
    } else if (i % 3 == 1) {
      b++;
    } else {
      c++;
    }
  }

  ori.arr[0][0] = ori.arr[1][1] = ori.arr[2][2] = a;
  ori.arr[0][1] = ori.arr[1][2] = ori.arr[2][0] = b;
  ori.arr[0][2] = ori.arr[1][0] = ori.arr[2][1] = c;
  res = quickpow(ori, n - 1);

  ans = (a * res.arr[0][0] + b * res.arr[1][0] + c * res.arr[2][0]) % MOD;
  printf("%d\n", ans);
}
