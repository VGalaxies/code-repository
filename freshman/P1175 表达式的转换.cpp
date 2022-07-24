#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<string>
#include<list>
#include<cmath>
using namespace std;
int main() {
	string ret = "";
	stack<char> str;
	string s;
	cin >> s;
	int len = s.size();//s.length();
	int i = 0;
	while (i < len) {
		switch (s[i])
		{
			char tmp;
		case'+':
		case'-':
			if (!str.empty()) {
				tmp = str.top();
				while (tmp == '*' || tmp == '/'|| tmp == '+' || tmp == '-'|| tmp == '^') {
					ret += tmp;
					cout << tmp << " ";
					str.pop();
					if (!str.empty())
						tmp = str.top();
					else
						break;
				}
			}
			str.push(s[i]);
			break;
		case'*':
		case'/':
			if (!str.empty()) {
				tmp = str.top();
				while (tmp == '*' || tmp == '/' || tmp == '^') {
					ret += tmp;
					cout << tmp << " ";
					str.pop();
					if (!str.empty())
						tmp = str.top();
					else
						break;
				}
			}
			str.push(s[i]);
			break;
		case'^':
			str.push(s[i]);
			break;
		case'(':
			str.push(s[i]);
			break;
		case')':
			if (!str.empty()) {
				tmp = str.top();
				while (tmp != '(') {
					ret += tmp;
					cout << tmp << " ";
					str.pop();
					if (!str.empty())
						tmp = str.top();
					else
						break;
				}
			}
			str.pop();//µ¯³ö'('
			break;
		default:
			ret += s[i];
			cout << s[i] << " ";
			break;
		}
		i++;
	}
	while (!str.empty()) {
		ret += str.top();
		cout << str.top() << " ";
		str.pop();
	}
	cout << endl;

	list<int> st;
	for (unsigned int i = 0; i < ret.size(); i++) {
		if (isdigit(ret[i]))   
			st.push_back(ret[i] - '0');
		else {               
			int a, b, tmp_res;
			a = st.back();
			st.pop_back();
			b = st.back();
			st.pop_back();
			switch (ret[i]) {
			case '+':
				tmp_res = b + a;
				break;
			case '-':
				tmp_res = b - a;
				break;
			case '*':
				tmp_res = b * a;
				break;
			case '/':
				tmp_res = b / a;
				break;
			case '^':
				tmp_res = (int)pow(b, a);
				break;
			}
			st.push_back(tmp_res);
			for (list<int>::iterator it = st.begin(); it != st.end(); ++it)
				cout << *it << ' ';             
			for (unsigned int j = i + 1; j < ret.size(); j++)
				cout << ret[j] << ' ';    
			cout << endl;
		}
	}
}