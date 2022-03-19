#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
inline unsigned int length(const char* s) {
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
inline void copy(char* dst, const char* src) {
	int index = 0;
	int len_dst = length(src);
	while (index < len_dst) {
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
}
int main() {
	char s1[10];
	char s2[10] = "Hello";
	copy(s1, s2);
	printf("%s", s1);
}