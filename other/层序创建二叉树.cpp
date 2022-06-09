#include<iostream>
#include<queue>
using namespace std;
struct node {
	int no, height;
	node* l, * r;
};
node* root;
queue<node*> q;
int n, l, r;
int steps, ans£¬vis;

int main() {
	cin >> n;
	root = new node;
	root->no = 0;
	root->height = 0;
	root->l = nullptr;
	root->r = nullptr;
	q.push(root);
	for (int i = 0; i < n; ++i) {
		node* fa = q.front();
		q.pop();
		cin >> l >> r;
		if (l != -1) {
			fa->l = new node;
			fa->l->no = l;
			fa->l->height = fa->height + 1;
			fa->l->l = fa->l->r = nullptr;
			q.push(fa->l);
		}
		else
			fa->l = nullptr;
		if (r != -1) {
			fa->r = new node;
			fa->r->no = r;
			fa->r->height = fa->height + 1;
			fa->r->l = fa->r->r = nullptr;
			q.push(fa->r);
		}
		else
			fa->r = nullptr;
	}
}