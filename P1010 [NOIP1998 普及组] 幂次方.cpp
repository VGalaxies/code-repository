#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int n;
string aid[] = { "","2(0)","2","2+2(0)", "2(2)" ,"2(2)+2(0)","2(2)+2","2(2)+2+2(0)","2(2+2(0))" };
inline int near(int x) {
	for (int i = 0; i <= 32; ++i)
		if (pow(2, i) <= x && pow(2, i + 1) > x)
			return i;
}
void fun(int x) {
	if (x >= 1 && x <= 8)
		cout << aid[x];
	else {
		int tmp = near(x);
		if (x - pow(2, tmp) == 0) {
			cout << "2(";
			fun(tmp);
			cout <<  ")";
		}
		else {
			cout << "2(";
			fun(tmp);
			cout << ")+";
			fun(x - pow(2, tmp));
		}
	}
}
int main() {
	cin >> n;
	fun(n);
}