#include<stdio.h>
#include<iostream>
#include<set>
#include<string>
using namespace std;
int n;
set<int> ori;
multiset<int> now;
int main() {
	cin >> n;
	string order;
	int operand;
	for (int i = 0; i < n; ++i) {
		cin >> order;
		if (order == "add") {
			cin >> operand;
			ori.insert(operand);
			now.insert(operand);
			printf("%d\n", now.count(operand));
		}
		else if (order == "ask") {
			cin >> operand;
			int count = ori.count(operand);
			if (count) {
				printf("1 %d\n", now.count(operand));
			}
			else
				printf("0 0\n");
		}
		else {
			cin >> operand;
			printf("%d\n", now.count(operand));
			multiset<int>::iterator p = now.find(operand);
			if (p != now.end()) {
				pair<multiset<int>::iterator, multiset<int>::iterator> range= now.equal_range(operand);
				now.erase(range.first, range.second);
			}
		}
	}
}