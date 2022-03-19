#include<iostream>
using namespace std;
int cases;
int binary(int k, int n) {
	int count = k;
	while (n != 0) {
		if (n % 2)
			return count;
		n /= 2;
		count--;
	}
}
int main() {
	int k, n;
	cin >> cases;
	while (cases--) {
		cin >> k >> n;
		cout << binary(k, n) << endl;
	}
}