#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.get();
	char s[55];
	cin.get(s, 50);
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] + n % 26 > 'z')
			s[i] = s[i] + n % 26 - 26;
		else
			s[i] = s[i] + n % 26;
	}
	for (int i = 0; i < strlen(s); ++i)
	{
		cout << s[i];
	}
	return 0;
}