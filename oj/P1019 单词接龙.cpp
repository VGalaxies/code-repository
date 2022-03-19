#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int n;
char str[21][100];
int times[21];
char head[3];
int count = 0;
int max = 0;
int Match(char* a, char* b) {
	char tmp[100] = { 0 };
	int len = strlen(a);
	if (len == 1) {
		if (a[0] == b[0])
			return 1;
	}
	else {
		for (int j = len - 1; j >= 1; --j) {
			for (int i = j; i <= len; ++i)
				tmp[i - j] = a[i];
			bool judge = true;
			for (int i = 0; i < len - j; ++i) {
				if (tmp[i] != b[i])
					judge = false;
			}
			if (judge)
				return len - j;//返回重叠长度
		}
	}
	return 0;//无重叠
}
void Search(char* tail) {
	for (int i = 0; i < 2 * n; ++i) {
		int match = Match(tail, str[i%n]);
		if (match && times[i % n]) {
			times[i % n]--;
			count +=  strlen(str[i % n]) - match;
			Search(str[i % n]);
			count -=  strlen(str[i % n]) - match;
			times[i % n]++;
		}
	}
	max = (count >= max) ? count : max;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str[i]);
		times[i] = 2;
	}
	scanf("%s", head);
	for (int i = 0; i < n; ++i) {
		int match = Match(head, str[i]);
		if (match) {
			count += strlen(str[i]);
			times[i % n]--;
			Search(str[i]);
			times[i % n]++;
			count -= strlen(str[i]);
		}
	}
	printf("%d", max);
}