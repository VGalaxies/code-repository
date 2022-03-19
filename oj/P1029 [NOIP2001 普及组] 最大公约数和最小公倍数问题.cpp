#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int m, n, a, b, ans;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool judge(int x) {
	int y = double(a) / x * b;
	int tmp = gcd(x, y);
	return tmp == a && x / tmp * y == b;
}
int main() {
	cin >> m >> n;
	a = min(m, n);
	b = max(m, n);
	int up = floor(sqrt(a) * sqrt(b));
	for (int i = a; i <= up; ++i) {
		if (judge(i))
			ans++;
	}
	if (a == up)
		cout << ans;
	else
		cout << ans * 2;
}