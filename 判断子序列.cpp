#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
char str[100];
char substr[100];
unsigned int Strlen(const char* str) {
	const char* eos = str;
	while (*eos++);
	return(eos - str - 1);
}

bool sub_judge(char* ori, char* sub) {
	char tmp[100];
	int len_ori = Strlen(ori);
	int len_sub = Strlen(sub);
	static int i = 0;
	for (; i < len_ori; ++i) {
		if (ori[i] == sub[0]) {
			if (Strlen(sub) == 1)
				return true;
			i++;
			break;
		}
	}
	if (i == len_ori) 
		return false;
	else {
		for (int j = 1; j <= len_sub; ++j) {
			tmp[j - 1] = sub[j];
		}
		return sub_judge(ori, tmp);
	}
}
int main() {
	scanf("%s", str);
	scanf("%s", substr);
	bool judge = sub_judge(str, substr);
	if (judge)
		printf("YES");
	else
		printf("NO");

}