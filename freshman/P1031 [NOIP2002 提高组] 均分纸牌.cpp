#include<iostream>
using namespace std;
int n, sum, ans;
int ori[110];
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> ori[i];
		sum += ori[i];
	}
	sum /= n;
	for (int i = 1; i <= n; ++i) {
		ori[i] -= sum;
	}
	for (int i = 1; i < n; ++i) {
		if (ori[i] == 0)
			continue;
		ori[i + 1] += ori[i];
		ans++;
	}
	cout << ans;
}