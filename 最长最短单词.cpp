#include<iostream>
#include<cstring>
using namespace std;
char a[20020];
int main()
{
	int count = 0, max = 0, min = 101;
	cin.getline(a, 20020);
	int c=0, d=0;   //定义初始位
	int len = strlen(a);
	for (int i = 0; i<=len; ++i)  //i<=20020就不对了
	{
		if (a[i] != ' ' && a[i] != ',' && a[i] != '\0')
			count++;    //统计单词长度
		else  //说明执行到了' '或','或'\0'
		{
			if (count > max)
			{
				max = count;
				c = i - max;
			}
			if (count < min)
			{
				min = count;
				d = i - min;
			}
			count = 0;
		}	
	}
	for (int i = c; i <= c + max; ++i)
	{
		cout << a[i];
	}
	cout << endl;
	for (int i = d; i <= d + min; ++i)
	{
		cout << a[i];
	}
	return 0;
}


/*   错解（多了一重循环）
for (int i = 0; i <= length; ++i)
	{
		while (a[i] != ' ' && a[i] != ',' && a[i] != '\0')
		{
			count++;
			if (count >= max)
				max = count;
			if (count <= min)
				min = count;
		}
		count = 0;
	}
*/