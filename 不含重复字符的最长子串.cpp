#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char str[100];
int MyStrlen(const char* a)
{
	if ('\0' == *a)
		return 0;
	else
		return MyStrlen(a + 1) + 1;
}
int main() {
	scanf("%s", str);
	int len = MyStrlen(str);
	int max_len = 0;
	for (int st = 0; st < len; ++st) {
		int tmp_len = 0;
		for (int ed = st + 1; ed < len; ++ed) {
			int i = st;
			for (; i < ed; ++i) {
				if (str[ed] == str[i])
					break;
			}
			if (i == ed) {
				tmp_len = ed - st + 1;
				max_len = (max_len > tmp_len) ? max_len : tmp_len;
			}
			else {
				st = i;//下一个字串起点下标为i+1
				break;
			}
		}
	}
	printf("%d", max_len);
}