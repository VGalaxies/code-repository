#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int cases;
int num;
int max_index;
int min_index;
char str[110][50];
int compare(char* a, char* b) {
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] == '\0' || a[i] < b[i])
			return -1;
		else if (b[i] == '\0' || a[i] > b[i])
			return 1;
		else
			i++;
	}
	return 0;
}
int main() {
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &num);
		for (int i = 0; i < num; ++i)
			scanf("%s", &str[i]);
		for (int i = 0; i < num; ++i) {
			if (compare(str[max_index], str[i]) < 0)
				max_index = i;
			if(compare(str[min_index], str[i]) > 0)
				min_index = i;
		}
		printf("%s %s\n", str[min_index], str[max_index]);
	}
}