#include<iostream>
using namespace std;
using ll = long long int;
ll n, q;
ll partial_arr[1000010];
ll aid[1000010];
inline ll lowbit(ll x) {
	return x & -x;
}
inline void add(ll* arr, ll x, ll k) {
	for (ll i = x; i <= n; i += lowbit(i)) {
		arr[i] += k;
	}
}
inline ll query(ll* arr, ll x) {
	ll ans = 0;
	for (ll i = x; i >= 1; i -= lowbit(i)) {
		ans += arr[i];
	}
	return ans;
}
int main() {
	cin >> n >> q;
	ll opcode, tmp, last_tmp = 0;
	for (ll i = 1; i <= n; ++i) {
		cin >> tmp;
		add(partial_arr, i, tmp - last_tmp);
		add(partial_arr, i, (i - 1) * (tmp - last_tmp));
		last_tmp = tmp;
	}
	for (ll i = 0; i < q; ++i) {
		cin >> opcode;
		if (opcode == 1) {
			ll s, t, r;
			cin >> s >> t >> r;
			add(partial_arr, s, r);
			add(partial_arr, t + 1, -r);
			add(aid, s, (s - 1) * r);
			add(aid, t + 1, -t * r);
		}
		else {
			ll s, t;
			cin >> s >> t;
			cout << (t * query(partial_arr, t) - query(partial_arr, t)) -
				((s - 1) * query(aid, s - 1) - query(aid, s - 1))
				<< endl;
		}
	}
}