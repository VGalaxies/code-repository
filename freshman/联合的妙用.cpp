#include<iostream>
using namespace std;
int trans(float f) {
	union {
		int i;
		float f;
	}tran;
	tran.f = f;
	return tran.i;
}
int main() {
	cout << trans(5.0);
}