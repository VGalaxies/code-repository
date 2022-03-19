#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
string s;
stack<int> num;
stack<char> symbol;
int trans(const char s) {
	switch (s)
	{
	case'(':return 1;
	case'+':case'-':return 2;
	case'*':case'/':return 3;
	case')':return 4;
	}
}
int calculate(const char op, int a, int b) {
	switch (op)
	{
	case'+':return a + b;
	case'-':return a - b;
	case'*':return a * b;
	case'/':return a / b;
	}
}
int main() {
	cin >> s;
	for (auto i : s) {
		if (isdigit(i)) {
			num.push(i - '0');
		}
		else {
			if (i == '+' || i == '-' || i == '*' || i == '/') {
				if (symbol.empty())
					symbol.push(i);
				else {
					char top = symbol.top();
					while (trans(top) >= trans(i) && !symbol.empty()) {
						symbol.pop();
						char a = num.top();
						num.pop();
						char b = num.top();
						num.pop();
						num.push(calculate(top, b, a));
						if (symbol.empty())
							break;
						else
							top = symbol.top();
					}
					symbol.push(i);
				}
			}
			else if (i == '(') {
				symbol.push(i);
			}
			else {
				char top = symbol.top();
				while (top != '(') {
					symbol.pop();
					char a = num.top();
					num.pop();
					char b = num.top();
					num.pop();
					num.push(calculate(top, b, a));
					if (symbol.empty())
						break;
					else
						top = symbol.top();
				}
				symbol.pop();
			}

		}
	}
	while (!symbol.empty()) {
		char top = symbol.top();
		char a = num.top();
		num.pop();
		char b = num.top();
		num.pop();
		num.push(calculate(top, b, a));
		symbol.pop();
		if (symbol.empty())
			break;
		else
			top = symbol.top();
	}
	cout << num.top();
}