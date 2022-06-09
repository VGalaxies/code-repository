#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
int num_order;
char order[10];
int operand1;
int operand2;
list<int> ori[10010];
int main() {
	cin >> num_order;
	for (int i = 0; i < num_order ;++i) {
		cin >> order;
		switch (order[0]) {
		case 'n':
			cin >> operand1;
			break;
		case 'a':
			cin >> operand1 >> operand2;
			ori[operand1].push_back(operand2);
			break;
		case 'm':
			cin >> operand1 >> operand2;
			ori[operand1].merge(ori[operand2]);
			break;
		case 'o': {
			cin >> operand1;
			if (!ori[operand1].empty()) {
				list<int>::iterator st = ori[operand1].begin();
				list<int>::iterator ed = ori[operand1].end();
				for (; st != ed; ++st)
					cout << *st << " ";
				cout << endl;
			}
			break;
		}
		case 'u':
			cin >> operand1;
			ori[operand1].sort();
			ori[operand1].unique();
			break;
		}
	}
}