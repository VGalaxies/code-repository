#include<iostream>
using namespace std;
int n, k;
int ans = 0;
void DFS(int n, int k, int steps) {
	if (steps == n) {
		ans++;
		return;
	}
	if (k >= 1)
		DFS(n, k - 1, steps + 1);
	DFS(n, k + 1, steps + 1);
}
int main() {
	cin >> n >> k;
	DFS(n, k, 0);
	cout << ans;
}