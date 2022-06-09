#include<iostream>
#include<algorithm>
using namespace std;
int arr[110][110];
int partial_arr[110][110];
int n, m, max_k;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}
	}
	partial_arr[1][1] = arr[1][1];
	for (int i = 1; i <= n; ++i) {
		partial_arr[i][1] = arr[i][1] + partial_arr[i - 1][1];
	}
	for (int j = 1; j <= m; ++j) {
		partial_arr[1][j] = arr[1][j] + partial_arr[1][j - 1];
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			partial_arr[i][j] = partial_arr[i - 1][j] + partial_arr[i][j - 1] - partial_arr[i - 1][j - 1] + arr[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = min(n - i, m - j); k >= 0; --k) {
				int I = i + k;
				int J = j + k;
				int test = partial_arr[I][J] - partial_arr[i - 1][J] - partial_arr[I][j - 1] + partial_arr[i - 1][j - 1];
				if (test == (k + 1) * (k + 1))
					max_k = max(max_k, k + 1);
			}
		}
	}
	cout << max_k;
}