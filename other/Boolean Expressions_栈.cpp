#include<iostream>
#include<cstdio>
#include<string>
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
	case'|':return 2;
	case'&':return 3;
	case'!':return 4;
	case')':return 5;
	}
}
int calculate(const char op, int a, int b) {
	switch (op)
	{
	case'|':return a | b;
	case'&':return a & b;
	}
}
void cycle() {

}
int i = 0;
int main() {
	while (getline(cin, s)) {
		i++;
		for (auto i : s) {
			if (i == 'V')
				num.push(1);
			else if (i == 'F')
				num.push(0);
			else {
				if (i == '|' || i == '&' || i == '!') {
					if (symbol.empty())
						symbol.push(i);
					else {
						char top = symbol.top();
						while (trans(top) >= trans(i) && !symbol.empty()) {
							symbol.pop();
							if (top == i && top == '!')
								goto L;
							if (top == '|' || top == '&') {
								char a = num.top();
								num.pop();
								char b = num.top();
								num.pop();
								num.push(calculate(top, b, a));
							}
							else if (top == '!') {
								char a = num.top();
								num.pop();
								num.push(!a);
							}
							if (symbol.empty())
								break;
							else
								top = symbol.top();
						}
						symbol.push(i);
					L:;
					}
				}
				else if (i == '(') {
					symbol.push(i);
				}
				else if (i == ')') {
					char top = symbol.top();
					while (top != '(') {
						symbol.pop();
						if (top == '|' || top == '&') {
							char a = num.top();
							num.pop();
							char b = num.top();
							num.pop();
							num.push(calculate(top, b, a));
						}
						else if (top == '!') {
							char a = num.top();
							num.pop();
							num.push(!a);
						}
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
			symbol.pop();
			if (top == '|' || top == '&') {
				char a = num.top();
				num.pop();
				char b = num.top();
				num.pop();
				num.push(calculate(top, b, a));
			}
			else if (top == '!') {
				char a = num.top();
				num.pop();
				num.push(!a);
			}
			if (symbol.empty())
				break;
			else
				top = symbol.top();
		}
		if (num.top()) {
			printf("Expression %d: V\n", i);
		}
		else {
			printf("Expression %d: F\n", i);
		}
		num.pop();
	}
}