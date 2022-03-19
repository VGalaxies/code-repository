#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char next[100];
char start[100];
int strlen(char* s) {
	int len = 0;
	while (*(s + len) != '\0') {
		len++;
	}
	return len;
}
void buildNext(int lenPattern, char* pattern) {
	next[0] = 0;

	int i = 0; 
	int x = 1; 
	int now = 0;

	while (x < lenPattern) {
		if (pattern[now] == pattern[x]) {
			now++; x++;
			next[++i] = now;
		}
		else if (now != 0) {
			now = next[now - 1];
		}
		else {
			next[++i] = 0; 
			x++;
		}
	}
}

void search(char* str, char* pattern) {
	int tar = 0;
	int position = 0;


	while (tar < strlen(str)) {
		if (str[tar] == pattern[position]) {
			tar++;
			position++;
		}
		else if (position != 0) {
			position = next[position - 1];
		}
		else {
			tar++;
		}

		if (position == strlen(pattern)) {
			//printf("%d\n", tar-position+1); 
			start[tar-position] = strlen(pattern);
			position = next[position-1];
		}
	}
}
int main() {
	char str[100]; 
	char target[100];

	scanf("%s%s", str, target);
	int lenStr = strlen(str);
	int lenTarget = strlen(target);

	for (int i = 0; i < 100; i++) {
		start[i] = 0;	//³õÊ¼»¯
	}

	buildNext(lenTarget, target);
	search(str, target);

	for (int i = 0; i < lenStr; i++) {
		if (start[i] != 0) {
			if (i != 0) 
				printf("\n"); 
			i += start[i] - 1; 
			if (start[i + 1] != 0) {
				printf("EmptyString");
			}
			continue;
		}
		printf("%c", str[i]);
	}
}