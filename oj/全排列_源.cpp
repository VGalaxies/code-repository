#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

char input[10];
char result[10];
int choice[10];
int length;

void next(int step)
{
	if (step == length)
	{
		for (int j = 0; j < length; j++)
			result[choice[j]] = input[j];
		for (int j = 0; j < length; j++)
			printf("%c", result[j]);
		printf("\n");
		return;
	}
	for (int i = 0; i < length; i++)
	{
		if (choice[i] == -1)
		{
			choice[i] = step;
			next(step + 1);
			choice[i] = -1;
		}
	}
	return;
}

int main()
{
	length = 0;
	cin >> input;
	while (input[length] != '\0')
		length++;
	for (int i = 0; i < 10; i++)
		choice[i] = -1;
	next(0);
	return 0;
}