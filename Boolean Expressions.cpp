#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool Boolean_exp();//���ʽ
bool Boolean_factor();//����

bool Boolean_exp()
{
	bool result = Boolean_factor();

	bool more = true;
	while (more)
	{
		char op = cin.peek();

		if (op == ' ')
			cin.get();

		else if (op == '|' || op == '&')
		{
			cin.get();
			bool value = Boolean_factor();

			if (op == '|') result |= value;
			else result &= value;
		}
		else more = false;
	}
	return result;
}

bool Boolean_factor()
{
	bool result;

	char c = cin.peek();
	while (c == ' ')
	{
		cin.get();
		c = cin.peek();
	}
	if (c == '(')
	{
		cin.get();
		result = Boolean_exp(); //ִ����exp()���������Ѿ������˿ո����Ƶ�������λ�ã�
		cin.get();
	}
	else if (c == '!')
	{
		cin.get();
		result = !Boolean_factor();
	}
	else
	{
		if (c == 'F') result = false;
		else if (c == 'V')result = true;
		cin.get();
	}

	return result;

}
int main() {

	while (cin.peek() != EOF)
	{
		if (Boolean_exp()) cout << "V" << endl;
		else cout << "F" << endl;

		cin.get(); // ɾ�����з� 
	}
	return 0;
}
