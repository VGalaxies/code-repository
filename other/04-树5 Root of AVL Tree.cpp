#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
	return a > b ? a : b;
}

typedef struct node* tree;
struct node {
	int ele;
	int height;
	tree left;
	tree right;
};
int get_height(tree tr) {
	if (tr)
		return tr->height;
	return 0;
}

int update_height(tree tr) {
	if (!tr)
		return 0;
	return tr->height = max(update_height(tr->left), update_height(tr->right)) + 1;
}

tree L_Rotation(tree tr) {
	tree new_root = tr->left;
	tree ori_root_LR = tr->left->right;
	tr->left = ori_root_LR;
	new_root->right = tr;
	update_height(new_root);
	return new_root;
}
tree R_Rotation(tree tr) {
	tree new_root = tr->right;
	tree ori_root_RL = tr->right->left;
	tr->right = ori_root_RL;
	new_root->left = tr;
	update_height(new_root);
	return new_root;
}
tree LR_Rotation(tree tr) {
	tr->left = R_Rotation(tr->left);
	tr = L_Rotation(tr);
	return tr;
}
tree RL_Rotation(tree tr) {
	tr->right = L_Rotation(tr->right);
	tr = R_Rotation(tr);
	return tr;
}

tree buildtree(tree tr, int n) {
	if (!tr) {
		tr = (tree)malloc(sizeof(struct node));
		if (tr) {
			tr->ele = n;
			tr->height = 0;
			tr->left = tr->right = NULL;
			return tr;
		}
	}
	if (n < tr->ele) {
		tr->left = buildtree(tr->left, n);
		update_height(tr);
		if (get_height(tr->left) - get_height(tr->right) == 2) {
			if (n < tr->left->ele) {
				tr = L_Rotation(tr);
			}
			else {
				tr = LR_Rotation(tr);
			}
		}
	}
	else if (n > tr->ele) {
		tr->right = buildtree(tr->right, n);
		update_height(tr);
		if (get_height(tr->right) - get_height(tr->left) == 2) {
			if (n > tr->right->ele) {
				tr = R_Rotation(tr);
			}
			else {
				tr = RL_Rotation(tr);
			}
		}
	}
	return tr;
}

int main() {
	int n, ele;
	tree root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ele);
		root = buildtree(root, ele);
	}
	printf("%d", root->ele);
}