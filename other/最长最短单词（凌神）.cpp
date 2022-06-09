#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a1[20010];
int a2[210];//用数组a2记录每个单词的起始位置
int main(void) {
	int j = 0;
	int max, min, tmp;
	cin.getline(a1, sizeof(a1));
	for (int i = 0; i < sizeof(a1); ++i) {
		if (a1[i] == ' ' || a1[i] == ',') {
			a2[j] = i;
			++j;
		}
		if (a1[i] == 0) {
			a2[j] = i;
			break;
		}
	}
	min = max = a2[0];
	int max_start = -1, max_end = a2[0];
	int min_start = -1, min_end = a2[0];
	for (int i = 1; i <= j; ++i) {
		tmp = a2[i] - a2[i - 1] - 1;
		if (tmp > max) {
			max = tmp;
			max_start = a2[i - 1];
			max_end = a2[i];
		}
		if (tmp < min) {
			min = tmp;
			min_start = a2[i - 1];
			min_end = a2[i];
		}
	}

	for (int i = max_start + 1; i < max_end; ++i) {
		printf("%c", a1[i]);
	}
	printf("\n");
	for (int i = min_start + 1; i < min_end; ++i) {
		printf("%c", a1[i]);
	}
	return 0;
}
/*另一种未完善的解法
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char max[101];
	char min[101];
	char tem[101];
	cin.get(max, 100,' ');
	strcpy_s(min, max);
	while (cin.get(tem, 100,' ')) {
		int x = strlen(max);
		int y = strlen(min);
		int z = strlen(tem);
		if (z > x)
			strcpy_s(max, tem);
		if (z < y)
			strcpy_s(min, tem);
		cin.get(tem, 100, ' ');
	}
	cout << max <<endl<< min;
	return 0;
}
*/
