#include<iostream>
#include<string>
using namespace std;
char a[15];
char b[1000010];
int main()
{
	
	int flag;
	int count = 0;       //ͳ���ַ����ִ���
	cin.get(a, 10);
	cin.get();
	cin.get(b, 1000000);
	int i = 0; 
	int j = 0;
	while(b[j]!='\0')
	{
		if (count == 0)
			flag = j;
		while (a[i] == b[j] || a[i] + 32 == b[j] || a[i] - 32 == b[j])
		{
			if (a[i + 1] == '\0' && (b[j + 1] == ' ' || b[j + 1] == '\0'))
			{
				count++;
				break;
			}
			else
			{
				++i;
				++j;
			}
		}
		i = 0;
		while (b[j++] != ' ' && b[j] != '\0')  //һ����ƥ�䣬�����õ���ʣ�µ�������ĸ
		{
		}
	}
	if (count==0)
		cout << -1;
	else
	{
		cout << count << " " << flag;
	}
	return 0;
}