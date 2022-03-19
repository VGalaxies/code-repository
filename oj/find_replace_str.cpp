#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char str[100];
char sub[100];
char replace[100];
int length(const char* s) {
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
int find_replace_str(char str[], const char find_str[], const char replace_str[]) {
	int count = 0;
	int len_1 = length(str);
	int len_2 = length(find_str);
	int len_3 = length(replace_str);
	int gap = len_2 - len_3;
	int index_1 = 0;
	while (index_1 < len_1) {
		int copy = index_1;
		int index_2 = 0;
		bool judge = true;
		while (index_2 < len_2) {
			if (str[index_1++] != find_str[index_2++])
				judge = false;
		}
		if (judge) {
			count++;
			int st = index_1 - index_2;
			int ed = index_1 - 1;
			if (gap == 0) {
				for (int i = st; i <= ed; ++i)
					str[i] = replace_str[i - st];
			}
			else if (gap > 0) {
				for (int i = index_1 - gap; i < len_1; ++i)
					str[i] = str[i + 1];
				for (int i = st; i <= ed - gap; ++i)
					str[i] = replace_str[i - st];
				index_1 = ed - gap + 1;
				len_1 -= gap;
			}
			else {
				for (int i = len_1 - 1; i >= index_1; --i)
					str[i - gap] = str[i];
				str[len_1 - gap] = '\0';
				for (int i = st; i <= ed - gap; ++i)
					str[i] = replace_str[i - st];
				index_1 = ed - gap + 1;
				len_1 += -gap;
			}
		}
		else {
			index_1 = copy + 1;
		}
	}
	return count;
}
int main() {
	scanf("%s%s%s", str, sub, replace);
	int ans = find_replace_str(str, sub, replace);
	printf("%d %s", ans, str);
}