#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
int n;
int ans = 0;
unordered_set<string> ori;
int main(){
	cin >> n;
	string tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (ori.find(tmp) == ori.end()) {
			ori.insert(tmp);
			ans++;
		}
	}
	cout << ans;
}
