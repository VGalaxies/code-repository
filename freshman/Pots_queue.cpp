#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 105;
struct pot {
	int k1, k2, op;
};
struct path {
	int x, y, op, step;
}path[maxn][maxn];
char str[][10] = { "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)",  "POUR(2,1)", "POUR(1,2)" };
int A, B, C;
bool judge[maxn][maxn];
void my_clear() {
	struct path h = { 0, 0, 0, 0 };
	memset(judge, 0, sizeof(judge));
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			path[i][j] = h;

}
// 递归打印路径 
void dfs(int x, int y) {
	int a = path[x][y].x;
	int b = path[x][y].y;

	if (path[x][y].step == 0) { //输出第一次操作 
		if (a == A)
			cout << str[0] << endl;
		if (b == B)
			cout << str[1] << endl;
		return;
	}
	dfs(a, b);
	cout << str[path[x][y].op] << endl;
}
void BFS(int v1, int v2, int L) {
	queue <pot> wat;
	pot start = { 0, 0, 0 };
	judge[0][0] = true;
	wat.push(start);
	while (!wat.empty()) {
		pot tep = wat.front();
		wat.pop();
		int temp;
		if (tep.k1 == L || tep.k2 == L) {
			cout << path[tep.k1][tep.k2].step << endl;
			dfs(tep.k1, tep.k2);
			return;
		}
		for (int i = 0; i < 6; i++) {
			switch (i) {
				/*6种状态*/
			case 0: start.k1 = v1, start.k2 = tep.k2; break;  			//A fill
			case 2: start.k1 = 0, start.k2 = tep.k2; break;				//A empty
			case 1: start.k1 = tep.k1; start.k2 = v2; break;			//B fill
			case 3: start.k1 = tep.k1; start.k2 = 0; break;			//B empty
			case 5: temp = tep.k1 + tep.k2 - v2;					//A -> B
				if (temp > 0) {
					start.k1 = temp;
					start.k2 = v2;
				}
				else {
					start.k1 = 0;
					start.k2 = tep.k1 + tep.k2;
				}
				break;
			case 4: temp = tep.k1 + tep.k2 - v1;						// B -> A
				if (temp > 0) {
					start.k2 = temp;
					start.k1 = v1;
				}
				else {
					start.k2 = 0;
					start.k1 = tep.k1 + tep.k2;
				}
				break;
			}
			if (!judge[start.k1][start.k2]) {
				path[start.k1][start.k2].x = tep.k1;
				path[start.k1][start.k2].y = tep.k2;//记录前驱结点 
				path[start.k1][start.k2].op = i;
				path[start.k1][start.k2].step = path[tep.k1][tep.k2].step + 1;
				judge[start.k1][start.k2] = true;

				wat.push(start);
			}
		}
	}
	cout << "impossible" << endl;
}
int main()
{
	while (cin >> A >> B >> C) {
		BFS(A, B, C);
		my_clear();
	}
	return 0;
}