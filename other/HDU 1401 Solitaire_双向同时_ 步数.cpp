#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

struct node {
	int pos[4][2];
}st, ed, cur;
bool flag;
int ans_step;
queue<node> path[2];
map<int, int> vis[2];

int Hash(node& p) {
	int index[] = { 0,1,2,3 };
	int code = 0;
	sort(index, index + 4, [&](int a, int b)
		{if (p.pos[a][0] != p.pos[b][0])
		return p.pos[a][0] < p.pos[b][0];
	return p.pos[a][1] < p.pos[b][1]; });
	for (int i = 0; i < 4; ++i)
		code = code * 8 + p.pos[index[i]][0];
	for (int i = 0; i < 4; ++i)
		code = code * 8 + p.pos[index[i]][1];
	return code;
}

bool Verify(node& p, int j, int k) {
	if (p.pos[j][0] < 1 || p.pos[j][0] > 8 || p.pos[j][1] < 1 || p.pos[j][1] > 8)
		return false;
	for (int i = 0; i < 4; ++i) {
		if (i == j)
			continue;
		if (p.pos[i][0] == p.pos[j][0] && p.pos[i][1] == p.pos[j][1]) {
			p.pos[j][0] += mov[k][0];
			p.pos[j][1] += mov[k][1];
			if (p.pos[j][0] < 1 || p.pos[j][0] > 8 || p.pos[j][1] < 1 || p.pos[j][1] > 8)
				return false;
			return true;
		}
	}
	return true;
}
void AID(int i,int step) {
	int size = path[i].size();
	while (size--) {
		cur = path[i].front();
		node now = cur;
		int code;
		path[i].pop();

		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				now = cur;
				now.pos[j][0] += mov[k][0];
				now.pos[j][1] += mov[k][1];
				if (Verify(now, j, k)) {
					code = Hash(now);
					if (vis[i].find(code) != vis[i].end())
						continue;
					if (vis[i ^ 1].find(code) != vis[i ^ 1].end()) {
						flag = true;
						ans_step = step + vis[i ^ 1].find(code)->second;
						return;
					}
					path[i].push(now);
					vis[i].insert(make_pair(code, step));
				}
			}
		}
	}
}
bool DFS() {
	int steps = 0;
	path[0].push(st);
	path[1].push(ed);
	int code_st = Hash(st);
	int code_ed = Hash(ed);
	if (code_st == code_ed)
		return true;
	vis[0].insert(make_pair(Hash(st), 0));
	vis[1].insert(make_pair(Hash(ed), 0));
	while (++steps <= 8) {
		if (steps % 2)
			AID(0, steps / 2 + 1);
		else
			AID(1, steps / 2);
		if (flag)
			return true;
	}
	return false;
}
int main() {
	for (int i = 0; i < 4; ++i)
		cin >> st.pos[i][0] >> st.pos[i][1];
	for (int i = 0; i < 4; ++i)
		cin >> ed.pos[i][0] >> ed.pos[i][1];
	if (DFS()) {
		cout << "YES" << endl;
		cout << ans_step;
	}
	else
		cout << "NO";
}