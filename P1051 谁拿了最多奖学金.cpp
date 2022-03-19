#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int n;
struct info {
	char name[25];
	int score_final;
	int score;
	char cadre;
	char western;
	int essay;
}Info[110];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s%d%d%c%c%d", &Info[i].name, &Info[i].score_final, &Info[i].score,
			&Info[i].cadre, &Info[i].western, &Info[i].essay);

}