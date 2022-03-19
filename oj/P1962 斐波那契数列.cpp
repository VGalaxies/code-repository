#include<iostream>
#include<cstring>
using namespace std;
const int n = 2;
const int mod = 1000000007;
typedef long long int ll;
ll k;
struct matrix{
	ll arr[n][n];
	matrix() {
		memset(arr, 0, sizeof(arr));
	}
	void build(const int n) {
		for (int i = 0; i < n; ++i)
			arr[i][i] = 1;
	}
	friend matrix operator *(const matrix& a, const matrix& b) {
		matrix re;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					re.arr[i][k] = (re.arr[i][k] + a.arr[i][j] * b.arr[j][k]) % mod;
		}
		return re;
	}
};
matrix quickpow(matrix b, ll q, ll k) {
	matrix ans;
	ans.build(n);
	do {
		if (q & 1)
			ans = ans * b;
		b = b * b;
		q >>= 1;
	} while (q);
	return ans;
}
int main() {
	cin >> k;
	matrix aid;
	aid.arr[1][0] = aid.arr[0][1] = aid.arr[1][1] = 1;
	aid = quickpow(aid, k - 1, mod);
	cout << (aid.arr[1][0] + aid.arr[0][0]) % mod;
}