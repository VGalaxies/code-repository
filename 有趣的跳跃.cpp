#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int ori[3005];
int gap[3005];
bool judge[3005];
bool _judge = true;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ori[i]);
	if (n == 1)
		printf("Jolly");
	else
	{
		for (int i = 0; i < n - 1; ++i)
			gap[i] = abs(ori[i + 1] - ori[i]);
		for (int j = 1; j <= n - 1; ++j)
			for (int i = 0; i < n - 1; ++i)
				if (gap[i] == j)
				{
					judge[j] = true;
					break;
				}
		for (int j = 1; j <= n - 1; ++j)
			if (!judge[j])
				_judge = false;
		if (_judge)
			printf("Jolly");
		else
			printf("Not jolly");
	}
	return 0;
}