#include<iostream>
#include<algorithm>
using namespace std;
int n, m, tmp;
int arr[10010];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		arr[i] = tmp;
	}
	for (int i = 0; i < m; ++i)
		next_permutation(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << ' ';
	}
}