#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ofstream cout("out.txt");
	cout << 2047 << endl;
	for (int i = 1; i <= 1023; ++i)
		cout << 2 * i - 1 << " " << 2 * i << endl;
	for (int i = 1; i <= 1024; ++i)
		cout << -1 << " " << -1 << endl;
}