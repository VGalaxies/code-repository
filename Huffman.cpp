#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;
struct node {
	string s;
	int f;
	node* l, * r;
	node(string _s, int _f, node* _l = nullptr, node* _r = nullptr) :s(_s), f(_f), l(_l), r(_r) {}
	bool operator <(const node& p) {
		return f < p.f;
	}
};
node* root = nullptr;
vector<node> ori;
string str, code;
string zero = "0";
string one = "1";
int frequency, index;
map<string, string> mp;
void travel(node* now, string next) {
	if (now != root)
		code += next;
	if (now->l == nullptr && now->r == nullptr) {
		mp[now->s] = code;
		code.erase(code.size() - 1);
		return;
	}
	travel(now->l, zero);
	travel(now->r, one);
	if (now != root)
		code.erase(code.size() - 1);

}
int main() {
	while (cin >> str >> frequency) {
		ori.push_back(node(str, frequency));
	}
	sort(ori.begin(), ori.end());
	while (index < ori.size()) {
		if (index == 0) {
			node p = ori[index++];
			node q = ori[index++];
			node* a = new node(p.s, p.f);
			node* b = new node(q.s, q.f);
			node* now = new node("", p.f + q.f, a, b);
			root = now;
		}
		else {
			node p = ori[index++];
			node* a = new node(p.s, p.f);
			if (a->f < root->f) {
				node* now = new node("", a->f + root->f, a, root);
				root = now;
			}
			else {
				node* now = new node("", a->f + root->f, root, a);
				root = now;
			}
		}
	}
	travel(root, zero);

}