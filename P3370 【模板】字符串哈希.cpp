#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
unsigned long long base = 131;
unsigned long long mod = 212370440130137957ll;
unsigned long long Hash(string s) {
	unsigned long long res = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		res = (res * base + (unsigned long long)s[i]);
	}
	return res;
}
unsigned long long arr[10010];
int n;
int ans = 0;
int main() {
	cin >> n;
	string tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		arr[i] = Hash(tmp);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (arr[i] != arr[i + 1])
			ans++;
	}
	cout << ans;
}
