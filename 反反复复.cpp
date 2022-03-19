#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ori[210];
char trans[25][110];
int n;
int main()
{
	scanf("%d", &n);
	scanf("%s", ori);
	int len = strlen(ori);
	int ori_index = 0;
	int row = 0;
	while (ori_index < len)
	{
		if (!(row % 2))
			for (int i = 0; i < n; ++i)
				trans[row][i] = ori[ori_index++];
		else
		{
			for (int i = n - 1; i >= 0; --i)
				trans[row][i] = ori[ori_index++];
		}
		row++;
	}
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < row; ++i)
			printf("%c", trans[i][j]);
}