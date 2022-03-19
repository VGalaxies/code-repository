#include<iostream>
using namespace std;
int n, q;
long long int arr[1000010];
inline int lowbit(int x) {
	return x & -x;
}
inline void add(int x, long long int k) {
	for (int i = x; i <= n; i += lowbit(i)) {
		arr[i] += k;
	}
}
inline long long int query(int x) {
	long long int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		ans += arr[i];
	}
	return ans;
}
int main() {
	cin >> n >> q;
	int tmp, opcode;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		add(i, tmp);
	}
	for (int i = 0; i < q; ++i) {
		cin >> opcode;
		if (opcode == 1) {
			int s, t;
			cin >> s >> t;
			add(s, t);
		}
		else {
			int s, t;
			cin >> s >> t;
			cout << query(t) - query(s - 1) << endl;
		}
	}
}