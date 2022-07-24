#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char str[100];
char substr[100];
unsigned int Strlen(const char* str) {
	const char* eos = str;
	while (*eos++);
	return(eos - str - 1);
}
int main() {
	scanf("%s", str);
	scanf("%s", substr);
	int len_str = Strlen(str);
	int len_substr = Strlen(substr);
	int count = 0;
	for (int i = 0; i < len_str; ++i) {
		int _i = i;
		int j = 0;
		while (str[_i] == substr[j]) {
			_i++, j++;
		}
		if (substr[j] == '\0')
			count++;
	}
	printf("%d", count);
}