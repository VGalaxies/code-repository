#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static void foo(char* args) {
	char* token = strtok(args, " ");
	if (token != NULL) {
		token = strtok(NULL, " ");
		puts(token);

		char* ptr;
		long i = strtol(token, &ptr, 10);
		printf("%d", i);

		token = strtok(NULL, " ");
		puts(token);
	}
}

int main() {
	char input[] = "x 10 0x12345678";
	foo(input);
}