#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
string s1;
string s2;
int pmt[100010];
int main() {
	cin >> s1 >> s2;
	pmt[0] = 0;
	for (int i = 1, j = 0; i < s2.length(); ++i) {
		while (j >= 0 && s2[i] != s2[j])
			j = j ? pmt[j - 1] : -1;
		pmt[i] = ++j;
	}
	for (int i = 0, j = 0; i < s1.length(); ++i) {
		while (j >= 0 && s1[i] != s2[j])
			j = j ? pmt[j - 1] : -1;
		++j;
		if (j == s2.length()) {
			cout << i - j + 2 << endl;
			j = pmt[j - 1];
		}
	}
	for (int i = 0; i < s2.length(); ++i)
		cout << pmt[i] << " ";
}