#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char str[100];
char target[10];
struct
{
	int st;
	int ed;
}spilt[110];
int MyStrlen(const char* p)
{
	int len = 0;
	while (p[len++] != '\0');
	return len - 1;
}
int main()
{
	scanf("%s%s", str, target);
	int len_str = MyStrlen(str);
	int len_target = MyStrlen(target);
	int index_str = 0;
	int index_spilt = 1;
	spilt[0].ed = -1;
	while (index_str < len_str)
	{	
		/*if (index_str + len_target >= len_str)
			break;*/
		bool judge = true;
		for (int i = 0;i<len_target; ++i)
			if (str[index_str + i] != target[i])
				judge = false;
		if (!judge)
			index_str++;
		else
		{
			spilt[index_spilt].st = index_str;
			spilt[index_spilt].ed = index_str + len_target - 1;
			index_spilt++;
			index_str += len_target;//
		}
	}
	spilt[index_spilt].st = len_str;
	for (int i = 0; i < index_spilt; ++i)
	{
		int ed = spilt[i].ed + 1;
		int st = spilt[i + 1].st - 1;
		if (ed > st)
		{
			if (ed == 0 || ed == len_str)
				continue;
			printf("%s\n", "EmptyString");
		}	
		else
		{
			for (int j = ed; j <= st; ++j)
				printf("%c", str[j]);
			printf("\n");
		}
	}
}