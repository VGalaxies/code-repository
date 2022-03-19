#include<iostream>
using namespace std;
struct {
	int index;
	int color;
}arr[10010];
int N, M;
int Z;
int X, Y;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		arr[i].index = i;
		arr[i].color = i;
	}
	for (int i = 0; i < M; ++i) {
		cin >> Z >> X >> Y;
		if (Z == 1) {
			int tmp = arr[Y].color;
			for (int j = 1; j <= N; ++j) {
				if (arr[j].color == tmp)
					arr[j].color = arr[X].color;
			}
		}
		else if (Z == 2) {
			if (arr[X].color == arr[Y].color)
				cout << 'Y';
			else
				cout << 'N';
			cout << endl;
		}
	}
}