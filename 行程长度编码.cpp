#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ori[1010];
char trans[1010];
struct result
{
	char word;
	int num;
}result[1010];
int main()
{
	scanf("%s", ori);
	int len = strlen(ori);
	for (int i = 0; i <= len; ++i)
		trans[i] = toupper(ori[i]);
	int index = 0;
	int result_index = 0;
	while (index < len)
	{
		int st = index;
		char tmp = trans[index++];
		while (trans[index] == tmp)
			index++;
		result[result_index].word = tmp;
		result[result_index].num = index - st;
		result_index++;
	}
	for (int i = 0; i < result_index; ++i)
		printf("(%c,%d)", result[i].word, result[i].num);
}