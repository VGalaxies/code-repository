#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char str[100];
unsigned int Strlen(const char* str) {
	const char* eos = str;
	while (*eos++);
	return(eos - str - 1);
}
int main() {
	scanf("%s", str);
	int len = Strlen(str);
	int max_len = 1;
	for (int st = 0; st < len; ++st) {
		for (int ed = st + 1; ed < len; ++ed) {
			if (str[ed] <= str[ed - 1]) {
				st = ed - 1;
				break;
			}
			else {
				if (max_len < ed - st + 1)
					max_len = ed - st + 1;
			}
		}
	}
	printf("%d", max_len);
}