#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
inline ll factor(ll a, ll b) {
	return (b == 0) ? a : factor(b, a % b);
}
struct fraction {
	ll a;
	ll b;
	fraction() :a(1), b(1) {}
	fraction(ll _a, ll _b) {
		ll aid = factor(_a, _b);
		a = _a / aid;
		b = _b / aid;
	}
	fraction operator-(const fraction& p) {
		fraction tmp;
		tmp.b = b * p.b;
		tmp.a = a * p.b - b * p.a;
		ll aid = factor(tmp.b, tmp.a);
		tmp.b /= aid;
		tmp.a /= aid;
		return tmp;
	}
};
ll a, b;
struct node {
	ll ans[100];
}cur;
queue<node> q;
bool flag;
void DFS(ll a, ll b, ll deep) {
	if (deep == 1) {
		ll down = floor(b * 1.0 / a);
		ll up = ceil(b * 1.0 / a);
		/*if (up >= 1000000)
			return;*/
		for (ll i = up; i <= down; ++i) {
			if (b == a * i) {
				cur.ans[deep - 1] = i;
				if (q.empty())
					q.push(cur);
				else {
					node best = q.back();
					if (best.ans[0] > i) {
						q.pop();
						q.push(cur);
					}
				}
				cur.ans[deep - 1] = 0;
				flag = true;
			}
		}
		return;
	}
	ll down = ceil(b * 1.0 / a);
	ll up = floor(b * deep * 1.0 / a);
	down = max(down, cur.ans[deep - 2] + 1);
	for (ll i = down; i < up; ++i) {
		fraction now(a, b);
		fraction minus(1, i);
		cur.ans[deep - 1] = i;
		now = now - minus;
		ll now_a = now.a;
		ll now_b = now.b;
		DFS(now_a, now_b, deep - 1);
	}
}
int main() {
	cin >> a >> b;
	fraction ori(a, b);
	ll ori_a = ori.a;
	ll ori_b = ori.b;
	ll deep = 1;
	do {
		memset(cur.ans, 0, sizeof(cur.ans));
		DFS(ori_a, ori_b, deep++);
	} while (!flag);
	node best = q.back();
	for (int i = deep - 2; i >= 0; --i)
		cout << best.ans[i] << " ";
}