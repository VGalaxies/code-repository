#include<iostream>
#include<string>
#include<set>
#include<queue>
using namespace std;
struct node {
	string s;
	int step;
	node(string _s, int _step) :s(_s), step(_step) {}
};
bool isnp[10010];
bool vis[10010];
set<int> prime;
queue<node> path;
int cases, flag;
string a, b;
void init() {
	for (int i = 2; i <= 10000; ++i) {
		if (!isnp[i])
			prime.insert(i);
		for (auto s : prime) {
			if (s * i > 10000)
				break;
			isnp[s * i] = true;
			if (i % s == 0)
				break;
		}
	}
}
int main() {
	init();
	cin >> cases;
	while (cases--) {
		flag = 0;
		memset(vis, 0, sizeof(vis));

		cin >> a >> b;
		path.push(node(a, 0));
		while (!path.empty()) {
			string cur = path.front().s;
			int now_step = path.front().step;
			path.pop();
			if (cur == b) {
				cout << now_step << endl;
				flag = 1;
				break;
			}
			string mem = cur;
			for (int i = 0; i < 4; ++i) {
				cur = mem;
				int prev = cur[i] - '0';
				for (int j = (i == 0) ? 1 : 0; j <= 9; ++j) {
					if (j == prev)
						continue;
					cur[i] = j + '0';
					int now = stoi(cur);
					if (prime.find(now) != prime.end() && !vis[now]) {
						path.push(node(cur, now_step + 1));
						vis[now] = true;
					}
				}
			}
		}
		if (!flag)
			cout << "Impossible" << endl;
	}
}