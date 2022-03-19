#include<iostream>
using namespace std;
struct node {
	int value;
	node* left, * right;
	node(int v = 0, node* l = nullptr, node* r = nullptr) :value(v), left(l), right(r) {}
};
int n, now;
node* buildtree(node* root,int val) {
	if (!root)
		root = new node(val);
	else {
		if (val < root->value)
			root->left = buildtree(root->left, val);
		else if (val > root->value)
			root->right = buildtree(root->right, val);
	}
	return root;
}
void preorder(node* root) {
	if (root) {
		cout << root->value << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void remove_tree(node* root) {
	if (root == nullptr)
		return;
	remove_tree(root->left);
	remove_tree(root->right);
	delete root;
}
int main() {
	while (cin >> n) {
		node* root = nullptr;
		for (int i = 0; i < n; ++i) {
			cin >> now;
			root = buildtree(root, now);
		}
		preorder(root);
		cout << endl;
		remove_tree(root);
	}
}