#include<iostream>
using namespace std;
int path[1010];
int n, pos;
bool IDA(int now, int step) {
	if (now > step)
		return false;
	if (path[pos] << (step - now) < n)
		return false;
	if (path[pos] == n)
		return true;
	pos++;
	for (int i = 0; i < pos; ++i) {
		path[pos] = path[pos - 1] + path[i];
		if (IDA(now + 1, step))
			return true;
		path[pos] = abs(path[pos - 1] - path[i]);
		if (IDA(now + 1, step))
			return true;
	}
	pos--;
	return false;
}
int main() {
	int steps = 0;
	while (cin >> n && n) {
		for (steps = 0;; ++steps) {
			path[pos = 0] = 1;
			if (IDA(0, steps))
				break;
		}
		cout << steps << endl;
	}
}