#include<iostream>
using namespace std;
unsigned long long int DP[25][25];
int DIRECTION_X[9] = { -2,-2,-1,-1,1,1,2,2,0 };
int DIRECTION_Y[9] = { -1,1,-2,2,-2,2,-1,1,0 };
int final_x, final_y;
int horse_x, horse_y;
int main() {
	cin >> final_x >> final_y >> horse_x >> horse_y;
	final_x += 2;
	final_y += 2;
	horse_x += 2;
	horse_y += 2;
	DP[2][2] = 1;
	for (int i = 2; i <= final_x; ++i) {
		for (int j = 2; j <= final_y; ++j) {
			bool judge = true;
			for (int k = 0; k < 9; ++k)
				if (i == horse_x + DIRECTION_X[k] && j == horse_y + DIRECTION_Y[k])
					judge = false;
			if (judge)
				DP[i][j] = max(DP[i][j], DP[i - 1][j] + DP[i][j - 1]);
		}
	}
	/*for (int i = 0; i <= final_x; ++i) {
		for (int j = 0; j <= final_y; ++j) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << DP[final_x][final_y];
}