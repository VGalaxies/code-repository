#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node* tree;
struct node {
	int ele;
	tree left;
	tree right;
};

tree buildtree(tree tr,int n) {
	if (!tr) {
		tr = (tree)malloc(sizeof(struct node));
		tr->ele = n;
		tr->left = tr->right = NULL;
		return tr;
	}
	if (n < tr->ele) {
		tr->left = buildtree(tr->left, n);
		return tr;
	}
	if (n > tr->ele) {
		tr->right = buildtree(tr->right, n);
		return tr;
	}
}
int isSame(tree R1, tree R2) {
	if ((R1 == NULL) && (R2 == NULL))
		return 1; /* both empty */
	if (((R1 == NULL) && (R2 != NULL)) || ((R1 != NULL) && (R2 == NULL)))
		return 0; /* one of them is empty */
	if (R1->ele != R2->ele)
		return 0;
	return isSame(R1->left, R2->left) && isSame(R1->right, R2->right);
}
int main() {
	int n, l, ele;
	while (scanf("%d", &n)&&n) {
		scanf("%d", &l);
		tree root = NULL;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &ele);
			root = buildtree(root, ele);
		}
		tree sub = NULL;
		for (int i = 0; i < l; ++i) {
			sub = NULL;
			for (int i = 0; i < n; ++i) {
				scanf("%d", &ele);
				sub = buildtree(sub, ele);
			}
			if (isSame(root, sub))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}