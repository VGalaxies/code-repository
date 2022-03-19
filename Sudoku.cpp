#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cases;
int sudoku[10][10];
int zero[100][2];
int zero_index;
void DFS(int index) {
	if (index < 0) {
		bool judge = true;
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				int x_st = i * 3 - 3;
				int x_ed = i * 3 - 1;
				int y_st = j * 3 - 3;
				int y_ed = j * 3 - 1;
				int sum = 0;
				for (int x = x_st; x <= x_ed; ++x)
					for (int y = y_st; y <= y_ed; ++y)
						sum += sudoku[x][y];
				if (sum != 45)
					judge = false;
			}
		}

		if (judge) {
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					printf("%d", sudoku[i][j]);
				}
				printf("\n");
			}
		}
		return;
	}

	for (int k = 1; k <= 9; ++k) {
		int i = zero[index][0];
		int j = zero[index][1];

		bool judge = true;
		for (int p = 0; p < 9; ++p)
			if (sudoku[i][p] == k || sudoku[p][j] == k)
				judge = false;

		if (judge) {
			sudoku[i][j] = k;
			DFS(index - 1);
			sudoku[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d", &cases);
	getchar();
	for (int p = 0; p < cases; ++p) {
		memset(sudoku, 0, sizeof(sudoku));
		char c;
		zero_index = 0;
		for (int i = 0; i < 9; i++, getchar())
			for (int j = 0; j < 9; j++) {
				scanf("%c", &c);
				sudoku[i][j] = c - '0';
				if (sudoku[i][j] == 0) {
					zero[zero_index][0] = i;
					zero[zero_index][1] = j;
					zero_index++;
				}
			}
		DFS(zero_index - 1);
	}
}