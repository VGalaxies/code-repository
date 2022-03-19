#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int k, x;
int ori[100000];
int main()
{
	scanf("%d,%d", &k, &x);
	ori[0] = k;
	int index = 1;
	int ori_index = 0;
	while (index <= 100000)
	{
		if (x == ori[ori_index]) {
			printf("YES");
			return 0;
		}

		int tmp = 3 * ori[ori_index] + 1;
		bool judge = true;
		for (int i = 0; i < index; ++i) {
			if (ori[i] == tmp) {
				judge = false;
				break;
			}
		}
		if (judge)
			ori[index++] = tmp;

		tmp = 2 * ori[ori_index] + 1;
		judge = true;
		for (int i = 0; i < index; ++i) {
			if (ori[i] == tmp) {
				judge = false;
				break;
			}
		}
		if (judge) 
			ori[index++] = tmp;

		ori_index++;
	}
	printf("NO");
}