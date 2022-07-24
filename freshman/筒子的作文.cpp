#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
stack<int> sym_index;
stack<int> num;
stack<int> num_index;
int main() {
	cin >> s;
	int index = 0;
	while (s[index]) {
		if (s[index] == '[') {
			sym_index.push(index);
			index++;
			continue;
		}
		if (isdigit(s[index])) {
			num.push(stoi(s.substr(index)));
			num_index.push(index);
			while (isdigit(s[index]))
				index++;
			continue;
		}
		if (s[index] == ']') {
			int n = num.top();
			num.pop();
			int left_sym = sym_index.top();
			sym_index.pop();
			int left_num = num_index.top();
			num_index.pop();
			string tmp(s, left_sym + 1, index - left_sym - 1);
			string single(tmp);
			for (int i = 1; i < n; ++i)
				tmp += single;
			s.replace(left_num, index - left_num + 1, tmp);
			index--;
			continue;
		}
		index++;
	}
	cout << s;
}