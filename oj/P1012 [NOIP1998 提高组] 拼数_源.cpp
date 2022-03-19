#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string ori[200010];
int main() {
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	sort(ori, ori + n, [](const string& a, const string& b) {return a + b > b + a; });
	for (int i = 0; i < n; ++i)
		cout << ori[i];
}