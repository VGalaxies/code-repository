#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int p1, p2, p3;
char str[1000];
char expand[3000];
int main(){
	scanf("%d%d%d", &p1, &p2, &p3);
	scanf("%s", str);
	int index_ori = 0;
	int index = 0;
	while (true) {
		while (str[index_ori] != '-'&& str[index_ori] != '\0') {
			expand[index++] = str[index_ori++];
		}
		if (str[index_ori] == '\0')
			break;
		char before = str[index_ori - 1];
		char after = str[index_ori + 1];
		if (isalpha(before) && isalpha(after) && before < after) {
			if (before + 1 == after);
			else {
				if (p3 == 1) {
					char fill = 0;
					if (p1 == 1)
						fill = tolower(before);
					else if (p1 == 2)
						fill = toupper(before);
					else
						fill = '*';
					while (before + 1 < after) {
						int count = p2;
						if (p1 != 3)
							fill++;
						before++;
						while (count--)
							expand[index++] = fill;
					}
				}
				else {
					char fill = 0;
					if (p1 == 1)
						fill = tolower(after);
					else if (p1 == 2)
						fill = toupper(after);
					else
						fill = '*';
					while (after - 1 > before) {
						int count = p2;
						if (p1 != 3)
							fill--;
						after--;
						while (count--)
							expand[index++] = fill;
					}
				}
			}
			index_ori++;
		}
		else if(isdigit(before) && isdigit(after) && before < after) {
			if (before + 1 == after);
			else {
				if (p3 == 1) {
					char fill = 0;
					if (p1 == 3)
						fill = '*';
					else
						fill = before;
					while (before + 1 < after) {
						int count = p2;
						if (p1 != 3)
							fill++;
						before++;
						while (count--)
							expand[index++] = fill;
					}
				}
				else {
					char fill = 0;
					if (p1 == 3)
						fill = '*';
					else
						fill = after;
					while (after - 1 > before) {
						int count = p2;
						if (p1 != 3)
							fill--;
						after--;
						while (count--)
							expand[index++] = fill;
					}
				}
			}
			index_ori++;
		}
		else
			expand[index++] = str[index_ori++];
	}
	printf("%s", expand);
}