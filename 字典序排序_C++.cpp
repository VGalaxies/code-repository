/*
��19���ƻ���ĩ���ֵ�������-�иĶ�
Description
����һ����Сд��ĸ��ɵ��ַ�����������ֵ�������������С���ַ���
˵�����ֵ�����ָ�Ȱ��յ�һ����ĸ�� ��a��b��.....��z��˳������;�����һ����ĸ������ô�Ƚϵڶ����������������������ĸ������ȵ�����������ʲ�һ����(���磬sigh ��sight)�� ��ô�Ѷ�������ǰ��
Input
ÿ���������������й��ɣ���һ��Ϊһ������N����ʾ��N����������ַ������ڶ���ΪN����Сд��ĸ��ɵ��ַ������Ե����ո�ָ
1 <= N <= 100
1 <= Length of each string <= 40
Output
����ÿ��������������һ���д�ӡ�������ַ������ֵ�����С�������ַ������Ե����ո�ָ�
*/
#include<iostream>
#include<cstring>
using namespace std;
char ori[50000];
int main()
{
	char max[50];
	char min[50];
	cin.getline(ori, sizeof(ori));
	int count = 0;
	for (int i = 0; i <= sizeof(ori); ++i)
	{
		if (ori[i] != ' ')
			count++;
		else
			break;
	}
	strncpy_s(max, ori, count);
	strncpy_s(min, ori, count);	//��ʼ�ֵ�����С�����Ϊ��һ���ַ���
	int i = count + 1;
	for(;ori[i]!='\0';++i)
	{
		char tmp[50];
		int k = 0;//tmp�е��±�
		int len = 0;//ÿ���ַ����ĳ���
		while (ori[i] != ' '&&ori[i]!='\0')
		{
			len++;
			i++;
		}
		if (ori[i] == ' '|| ori[i] == '\0')
		{
			for (int j = i - len + 1; j <= i; ++j)
				tmp[k++] = ori[j-1];
		}
		tmp[k] = '\0';
		if (strcmp(tmp, max) >= 0)
		{
			memset(max, '\0', 50);//max���
			strcpy_s(max, tmp);
		}
		else if (strcmp(tmp, min) <= 0)
		{
			memset(min, '\0', 50);//min���
			strcpy_s(min, tmp);
		}
	}
	cout << max << endl;
	cout << min;
	return 0;
}