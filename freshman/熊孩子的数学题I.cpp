#include<iostream>
#include<cstring>
using namespace std;
int a, b, c;
int judge[10] = { 0 };
void trans(int n)
{
	judge[n / 100] = 1;
	judge[n % 10] = 1;
	judge[(n - n % 10) / 10 % 10] = 1;
}
int main()
{
	for (int i = 123; i * 3 <= 987; ++i)
	{
		trans(i);
		trans(i * 2);
		trans(i * 3);
		int sum = 0;
		for (int j = 0; j <= 9; ++j)
			sum += judge[j];
		if (sum == 9 && !judge[0])
			cout << i << " " << i * 2 << " " << i * 3 << endl;
		memset(judge, 0, sizeof(judge));
	}
}