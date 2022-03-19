/*
【19级计基期末】字典序排序-有改动
Description
输入一组由小写字母组成的字符串，输出按字典序排列最大和最小的字符串
说明：字典序是指先按照第一个字母、 以a、b、.....、z的顺序排列;如果第一个字母样，那么比较第二个、第三个乃至后面的字母。如果比到最后两个单词不一样长(比如，sigh 和sight)， 那么把短者排在前。
Input
每个测试用例由两行构成，第一行为一个整数N，表示有N个待排序的字符串；第二行为N个由小写字母组成的字符串，以单个空格分割；
1 <= N <= 100
1 <= Length of each string <= 40
Output
对于每个测试用例，在一行中打印出给定字符串中字典序最小和最大的字符串，以单个空格分割
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
	strncpy_s(min, ori, count);	//初始字典序最小和最大为第一个字符串
	int i = count + 1;
	for(;ori[i]!='\0';++i)
	{
		char tmp[50];
		int k = 0;//tmp中的下标
		int len = 0;//每个字符串的长度
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
			memset(max, '\0', 50);//max清空
			strcpy_s(max, tmp);
		}
		else if (strcmp(tmp, min) <= 0)
		{
			memset(min, '\0', 50);//min清空
			strcpy_s(min, tmp);
		}
	}
	cout << max << endl;
	cout << min;
	return 0;
}