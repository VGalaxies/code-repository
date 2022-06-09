#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[200010];
int n;
int output[200010];
int main() {
	scanf("%d", &n);
	int index = 0;
	int out_index = 0;
	int weight = 0;
	while (n--) {
		int test = 0;
		scanf("%d", &test);
		switch (test)
		{
		case 0:
			scanf("%d", &weight);
			index++;
			stack[index] = weight > stack[index - 1] ? weight : stack[index - 1];
			break;
		case 1:
			stack[index] = 0;
			if (index > 0)
				index--;
			break;
		case 2:
			if (index > 0)
				output[out_index++] = stack[index];
			else
				output[out_index++] = 0;
			break;
		}
	}
	for (int i = 0; i < out_index; ++i)
		printf("%d\n", output[i]);
}