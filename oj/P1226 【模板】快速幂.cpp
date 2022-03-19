#include<iostream>
#include<cstdio>
using namespace std;
typedef long long int ll;
ll b, q, k;
ll quickpow(ll b,ll q,ll k) {
	ll ans = 1;
	do {
		if (q & 1)
			ans = ans * b % k;
		b = b * b % k;
		q >>= 1;
	} while (q);
	return ans % k;
}
int main() {
	cin >> b >> q >> k;
	printf("%lld^%lld mod %lld=%lld", b, q, k, quickpow(b, q, k));
}