#include<iostream>
#include<cstring>
using namespace std;
char ori[100];
int num_ori[100];
int num_reverse[100];
int num_result[100];
int carry[100];
bool reverse_judge(char* a)
{
	int len = strlen(ori);
	for (int i = 0; i < len / 2; ++i)
	{
		if (a[i] != a[len - 1 - i])
			return false;
	}
	return true;
}
void reverse_char(char* a)
{
	int len = strlen(ori);
	for (int i = 0; i < len / 2; ++i)
	{
		char tmp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tmp;
	}
}
void reverse_int(int* a)
{
	int len = strlen(ori);
	if (!a[len])
	{
		for (int i = 0; i < len / 2; ++i)
		{
			int tmp = a[i];
			a[i] = a[len - 1 - i];
			a[len - 1 - i] = tmp;
		}
	}
	else
	{
		for (int i = 0; i < len / 2; ++i)
		{
			int tmp = a[i];
			a[i] = a[len - i];
			a[len - i] = tmp;
		}
	}
	
}
void trans_char(char *a,int *b)
{
	int len = strlen(ori);
	for (int i = 0; i < len; ++i)
			b[i] = a[i] - '0';
}
void trans_int(char *a,int *b)
{
	int len = strlen(ori);
	if (carry[len-1])
	{
		for (int i = 0; i <= len; ++i)
			a[i] = b[i] + '0';
	}
	else
	{
		for (int i = 0; i < len; ++i)
			a[i] = b[i] + '0';
	}
	
}
void add(int* a, int* b,int *c,int k)//k进制
{
	int len = strlen(ori);
	for (int i = 0; i <= len; ++i)
	{
		if (a[i] + b[i] + carry[i-1] >= k)
		{
			c[i] = a[i] + b[i] + carry[i - 1] - k;
			carry[i] = 1;
		}
		else
		{
			c[i] = a[i] + b[i] + carry[i - 1];
		}
	}
}
int main()
{
	int k;
	cin >> k;
	cin.get();
	cin.getline(ori, 100);
	bool judge = false;
	int ans = 0;
	while (!judge && ans <= 30)
	{
		int len = strlen(ori);
		trans_char(ori, num_ori);
		reverse_char(ori);
		trans_char(ori, num_reverse);
		add(num_ori, num_reverse, num_result, k);
		trans_int(ori, num_result);
		len = strlen(ori);//更新长度（不减）
		reverse_char(ori);
		memset(carry, 0, sizeof(carry));
		if (!reverse_judge(ori))
		{
			ans++;
			judge = false;
		}
		else
		{
			ans++;
			judge = true;
		}
	}
	if (ans <= 30)
		cout << "STEP=" << ans << endl;
	else
		cout << "Impossible!" << endl;
	return 0;
}