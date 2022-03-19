#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 105;
const int mod = 1000000007;
typedef long long int ll;
ll n, k;
struct matrix{
	ll arr[MAX][MAX];
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
	cin >> n >> k;
	matrix ori, ans;
	int tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			ori.arr[i][j] = tmp;
		}
	}
	ans = quickpow(ori, k, mod);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans.arr[i][j] << ' ';
		}
		cout << endl;
	}
}