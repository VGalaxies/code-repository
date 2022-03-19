#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int DIRECTION_X[9] = { -2,-2,-1,-1,1,1,2,2,0 };
int DIRECTION_Y[9] = { -1,1,-2,2,-2,2,-1,1,0 };
int D_X[2] = { 0,1 };
int D_Y[2] = { 1,0 };
int final_x, final_y;
int horse_x, horse_y;
int ans;
void DFS(int i, int j) {
	if (i > final_x || j > final_y)
		return;
	if (i == final_x && j == final_y) {
		ans++;
		return;
	}
	for (int count = 0; count < 2; ++count) {
		bool judge = true;
		int x = i + D_X[count];
		int y = j + D_Y[count];
		for (int k = 0; k < 9; ++k)
			if (x == horse_x + DIRECTION_X[k] && y == horse_y + DIRECTION_Y[k])
				judge = false;
		if (judge)
			DFS(x, y);
	}
	return;

}
int main() {
	cin >> final_x >> final_y >> horse_x >> horse_y;
	DFS(0, 0);
	cout << ans;
}