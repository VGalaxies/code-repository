#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int strlen(char* s) {
	int len = 0;
	while (*(s + len) != '\0') {
		len++;
	}
	return len;
}
int main() {
	char str[100], target[100];

	scanf("%s", str);
	scanf("%s", target);

	int lenStr = strlen(str);
	int lenTarget = strlen(target); 
	int last[100];

	for (int i = 0; i < 100; i++) {
		last[i] = -1;
	}

	if (lenTarget > lenStr) {
		printf("%s\n", str);
	}
	else {
		int gap = lenStr - lenTarget;
		for (int i = 0; i <= gap; i++) {
			for (int j = 0; j < lenTarget; j++) {
				if (str[i + j] != target[j]) {
					break;
				}
				if (j == lenTarget - 1) {
					last[i] = i + j + 1;
				}
			}
		}
	}
	for (int i = 0; i < lenStr; i++) {
		if (last[i] == -1) {
			printf("%c", *(str + i));
		}
		else if (last[i] != -1 && last[last[i]] != -1) {
			i = last[i] - 1;
			printf("\n"); 
			printf("EmptyString");
		}
		else {
			if (i != 0) { 
				printf("\n");
			}
			i = last[i] - 1;
		}
	}
	return 0;
}