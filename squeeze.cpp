#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char a[50];
char b[50];
char c[50];
int length(char* s) {
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
void squeeze(char* s1, char* s2, char* s3) {
	int len_1 = length(s1);
	int len_2 = length(s2);
	int index_1 = 0;
	int index_2 = 0;
	int index_3 = 0;
	for (; index_2 < len_2; ++index_2) {
		index_1 = 0;
		while (index_1 < len_1) {
			while (s1[index_1] != s2[index_2]) {
				index_1++;
			}
			if (index_1 < len_1) {
				s3[index_3++] = s2[index_2];
				for (int i = index_1; i < len_1; ++i)
					s1[i] = s1[i + 1];
			}
		}	
	}
	s3[index_3] = '\0';
}
int main() {
	scanf("%s%s", a, b);
	squeeze(a, b, c);
	printf("%s %s", a, c);
}