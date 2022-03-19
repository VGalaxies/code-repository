#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ori[256];
int main() {
	scanf("%s", ori);
	int len = strlen(ori);
	int boy = 0;
	int girl = 0;
	int i = 0;
	for (i; i < len; ++i) {
		while (ori[i] == '.')
			i++;
		if (ori[i] == 'b'
			|| ori[i] == 'o' && ori[i - 1] != 'b'
			|| ori[i] == 'y' && ori[i - 1] != 'o' && ori[i - 2] != 'b') {
			boy++;
		}
		if (ori[i] == 'g'
			|| ori[i] == 'i' && ori[i - 1] != 'g'
			|| ori[i] == 'r' && ori[i - 1] != 'i' && ori[i - 2] != 'g'
			|| ori[i] == 'l' && ori[i - 1] != 'r' && ori[i - 2] != 'i' && ori[i - 2] != 'g') {
			girl++;
		}
	}
	printf("%d\n%d", boy, girl);
}