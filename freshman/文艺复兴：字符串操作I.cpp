#include<string>
#include<iostream>
using namespace std;
int main() {
	string s, opcode;
	getline(cin, s, '.');
	s += '.';
	cin >> opcode;
	string a, b;
	size_t pos;
	switch (opcode[0])
	{
	case 'D':
		cin >> a;
		pos = s.find(a);
		if (pos != s.npos) {
			s.erase(pos, 1);
			cout << s;
		}	
		else
			cout << "Not exist";
		break;
	case 'I':
		cin >> a >> b;
		pos = s.rfind(a);
		if (pos != s.npos) {
			s.insert(pos, b);
			cout << s;
		}	
		else
			cout << "Not exist";
		break;
	case 'R':
		cin >> a >> b;
		pos = s.find(a);
		if (pos == s.npos) {
			cout << "Not exist";
		}
		else {
			while (pos != s.npos) {
				s.replace(pos, 1, b);//�㷨��algorithm�е�replace��������һ����ȫ���滻
				pos = s.find(a);
			}
			cout << s;
		}
		break;
	}
}