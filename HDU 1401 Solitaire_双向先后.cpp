#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

struct node {
	int pos[4][2] = {};
	int steps = 0;
}st, ed, cur;
queue<node> path[2];
set<int> vis[2];
set<int> ans;

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

bool Verify(node& p, int j,int k) {
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

void DFS() {
	path[0].push(st);
	path[1].push(ed);
	vis[0].insert(Hash(st));
	vis[1].insert(Hash(ed));
	for (int i = 0; i < 2; ++i) {
		while (!path[i].empty()) {
			cur = path[i].front();
			node now = cur;
			int code;
			path[i].pop();
			int step = cur.steps;
			if (step++ > 4)
				break;

			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					now = cur;
					now.pos[j][0] += mov[k][0];
					now.pos[j][1] += mov[k][1];
					if (Verify(now, j, k)) {
						code = Hash(now);
						if (vis[i].find(code) == vis[i].end()) {
							now.steps = step;
							path[i].push(now);
							vis[i].insert(code);
						}
					}
				}
			}
		}
	}
}
int main() {
	for (int i = 0; i < 4; ++i)
		cin >> st.pos[i][0] >> st.pos[i][1];
	for (int i = 0; i < 4; ++i)
		cin >> ed.pos[i][0] >> ed.pos[i][1];
	DFS();
	set_intersection(vis[0].begin(), vis[0].end(), vis[1].begin(), vis[1].end(), inserter(ans, ans.begin()));
	if (!ans.empty())
		cout << "YES";
	else
		cout << "NO";
}