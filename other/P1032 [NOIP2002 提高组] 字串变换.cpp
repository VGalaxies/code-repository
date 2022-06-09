#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
string trans[6][2];
struct node {
	string str;
	int steps;
	node(string s, int n) :str(s), steps(n) {}
};
queue<node> q;
int main() {
	string a, b;
	cin >> a >> b;
	string trans_a, trans_b;
	int index = 0;
	while (cin >> trans_a >> trans_b) {
		trans[index][0] = trans_a;
		trans[index++][1] = trans_b;
	}
	q.push(node(a, 0));
	while (!q.empty()) {
		node front = q.front();
		if (front.steps > 10)
			break;
		for (int i = 0; i < index; ++i) {
			node tmp = front;
			int pos = tmp.str.find(trans[i][0], 0);
			while (pos != tmp.str.npos) {
				tmp.str.replace(pos, trans[i][0].length(), trans[i][1]);
				tmp.steps++;
				if (tmp.str == b) {
					cout << tmp.steps;
					return 0;
				}
				q.push(tmp);
				tmp = front;
				pos = tmp.str.find(trans[i][0], pos + 1);
			}
		}
		q.pop();
	}
	cout << "NO ANSWER!";
}