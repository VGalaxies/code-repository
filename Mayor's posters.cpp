#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN = 10010;
int t, n;
int ori[MAXN << 2];
int aid[MAXN << 2];
int poster[MAXN << 2];
int wall[MAXN << 3];
int tag[MAXN << 3];
void push_down(int rt) {
	if (tag[rt]) {
		wall[rt << 1] = wall[rt];
		wall[rt << 1 | 1] = wall[rt];
		tag[rt << 1] = 1;
		tag[rt << 1 | 1] = 1;
		tag[rt] = 0;
	}
}
void update(int a, int b, int c, int l, int r, int rt) {
	if (a <= l && b >= r) {
		wall[rt] = c;
		tag[rt] = 1;
		return;
	}
	push_down(rt);
    int mid = (l + r) >> 1;
    if (a <= mid) 
        update(a, b, c, l, mid, rt << 1);  
    if (b > mid) 
        update(a, b, c, mid + 1, r, rt << 1 | 1);
}

int main() {
	cin.tie(0);
	cin >> t;
	while (t--) {
		memset(ori, 0, sizeof(ori));
		memset(aid, 0, sizeof(aid));
		memset(poster, 0, sizeof(poster));
		memset(wall, 0, sizeof(wall));
		memset(tag, 0, sizeof(tag));

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> ori[i] >> ori[i + n];
			aid[i] = ori[i];
			aid[i + n] = ori[i + n];
		}
		sort(aid, aid + 2 * n);
		int l = unique(aid, aid + 2 * n) - aid; // l为不重复元素的数量
		for (int i = 0; i < 2 * n; ++i)
			poster[i] = lower_bound(aid, aid + l, ori[i]) - aid + 1;
		for (int i = 0; i < n; ++i)
			update(poster[i], poster[i + n], i + 1, 1, 2 * n, 1);
		for (int i = 0; i < 8 * n; ++i) // 清理标记		
			push_down(i);

		set<int> ans;
		for (int i = 0; i < 8 * n; ++i)
			if (wall[i])
				ans.insert(wall[i]);
		cout << ans.size() << endl;
	}
}