#include <iostream>
using namespace std;

size_t n;
int now;
unsigned min_abs = 1000005;
long long res = 0;
bool has_pos = false, has_neg = false;

int main() {
  cin >> n;

  if (n == 1) {
    cin >> now;
    cout << now;
    return 0;
  }

  for (size_t i = 0; i < n; ++i) {
    cin >> now;

    res += abs(now);
    if (abs(now) < min_abs)
      min_abs = abs(now);

    if (now >= 0) {
      has_pos = true;
    } else {
      has_neg = true;
    }
  }

  if (!(has_neg ^ has_neg))
    res -= 2 * min_abs;

  cout << res;
}
