#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

struct node
{
	bool flag;
	int num;
};

node loop[10005];
int prime[10005];
int number;
double a, b, m;

void init()
{
	int i, j;
	number = 0;
	for (i = 0; i < 10005; i++)
	{
		loop[i].flag = false;
		loop[i].num = 0;
	}
	for (i = 2; i < 10005; i++)
	{
		if (!loop[i].flag)
		{
			for (j = i * i; j < 10005; j = j + i)
				loop[j].flag = true;
		}
	}
	for (i = 2; i < 10005; i++)
	{
		if (!loop[i].flag)
		{
			prime[number] = i;
			loop[i].num = number;
			number++;
		}
	}
}

bool judge(int p, int q)
{
	double x = p * 1.0;
	double y = q * 1.0;
	if (x * y > m)
		return false;
	if (x / y > 1)
		return false;
	if (x / y < a / b)
		return false;
	return true;
}

int main()
{
	int i, j, d, p, q, max, ansp, ansq;
	init();
	while (scanf("%lf%lf%lf", &m, &a, &b) != EOF)
	{
		if (m == 0 && a == 0 && b == 0)
			break;
		max = 0;
		d = int(sqrt(m * b / a));
		for (i = d; i >= 2; i--)
		{
			if (!loop[i].flag)
				break;
		}
		int index = loop[i].num;
		for (i = 0; i <= index; i++)
		{
			for (j = i; j <= index; j++)
			{
				p = prime[i];
				q = prime[j];
				if (judge(p, q) && p * q > max)
				{
					max = p * q;
					ansp = p;
					ansq = q;
				}
			}
		}
		printf("%d %d\n", ansp, ansq);
	}
	return 0;
}
