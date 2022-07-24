#include<iostream>
using namespace std;
int n, q;
long long int partial_arr[1000010];
inline int lowbit(int x) {
	return x & -x;
}
inline void add(int x, long long int k) {
	for (int i = x; i <= n; i += lowbit(i)) {
		partial_arr[i] += k;
	}
}
inline long long int query(int x) {
	long long int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		ans += partial_arr[i];
	}
	return ans;
}
int main() {
	cin >> n >> q;
	int opcode;
	long long int tmp, last_tmp = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		add(i, tmp - last_tmp);
		last_tmp = tmp;
	}
	for (int i = 0; i < q; ++i) {
		cin >> opcode;
		if (opcode == 1) {
			int s, t, r;
			cin >> s >> t >> r;
			add(s, r);
			add(t + 1, -r);
		}
		else {
			int s;
			cin >> s;
			cout << query(s) << endl;
		}
	}
}