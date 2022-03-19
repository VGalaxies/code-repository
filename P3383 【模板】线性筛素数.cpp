#include<iostream>
#include<vector>
using namespace std;
bool isnp[100000010];
vector<int> prime;
int n, q;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		if (!isnp[i])
			prime.push_back(i);
		for (auto s : prime) {
			if (s * i > n)
				break;
			isnp[s * i] = true;
			if (i % s == 0)
				break;
		}
	}
	int query;
	for (int i = 0; i < q; ++i) {
		cin >> query;
		printf("%d\n", prime[query - 1]);
	}
}