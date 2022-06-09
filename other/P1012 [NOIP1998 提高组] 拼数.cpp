#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int n;
int arr[25];
char str[25][15];
char cat_str[250];
char* p[25];
void trans(int n, int i) {
	int index = 0;
	while (n != 0) {
		str[i][index] = n % 10 + '0';
		n = n / 10;
		index++;
	}
	for (int p = 0; p < index / 2; ++p) {
		char tmp = str[i][p];
		str[i][p] = str[i][index - p - 1];
		str[i][index - p - 1] = tmp;
	}
	str[i][index] = '\0';
}
int compare(const char* s1, const char* s2) {
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] > s2[i]) {
		if (s1[i - 1] == s2[i - 1] && s2[i] == '\0' && s1[i] < s2[0] && i >= 1)
			return -1;
		else
			return 1;

	}	
	else if (s1[i] < s2[i]) {
		if (s1[i - 1] == s2[i - 1] && s1[i] == '\0' && s2[i] < s1[0] && i >= 1)
			return 1;
		else
			return -1;
	}
	else
		return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		trans(arr[i], i);
		p[i] = str[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (compare(p[i], p[j]) < 0) {
				char* tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%s", p[i]);
	}
}