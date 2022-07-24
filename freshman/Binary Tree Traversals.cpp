#include<iostream>
using namespace std;
int n;
int pre[1010];
int in[1010];
int post[1010];
struct node {
	int value;
	node* left, * right;
	node(int v = 0, node* l = nullptr, node* r = nullptr) :value(v), left(l), right(r) {}
};
void buildtree(int l, int r, int& index, node* &root) {
	int flag = -1;
	for (int i = l; i <= r; ++i) {
		if (in[i] == pre[index]) {
			flag = i;
			break;
		}
	}
	if (flag == -1)
		return;
	root = new node(in[flag]);
	index++;
	if (flag > l)
		buildtree(l, flag - 1, index, root->left);
	if (flag < r)
		buildtree(flag + 1, r, index, root->right);
}
void postorder(node* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->value << " ";
	}
}
void inorder(node* root) {
	if (root) {
		inorder(root->left);
		cout << root->value << " ";
		inorder(root->right);
	}
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
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> pre[i];
	for (int i = 1; i <= n; ++i)
		cin >> in[i];
	node* root = new node;
	int index = 1;
	buildtree(1, n, index, root);
	postorder(root);
	remove_tree(root);
}