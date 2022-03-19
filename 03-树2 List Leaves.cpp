#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MaxTree 10 
#define Tree int
#define Null -1

struct TreeNode
{
	Tree Left;
	Tree Right;
} T[MaxTree];

int myQueue[MaxTree + 1];
int head = 0, tail = 1;

Tree BuildTree(struct TreeNode T[]) {
	int n = 0, root = Null;
	char cl = 0, cr = 0;
	int check[MaxTree];
	memset(check, 0, sizeof(check));

	scanf("%d\n", &n);
	if (n) {
		for (int i = 0; i < n; ++i) {
			scanf("%c %c\n", &cl, &cr);
			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (int i = 0; i < n; ++i)
			if (!check[i]) {
				root = i;
				break;
			}
	}
	return root;
}

void travel(Tree R) {
	myQueue[head] = R;
	while (head < tail) {
		Tree now = myQueue[head];
		head++;
		if (T[now].Left == Null && T[now].Right == Null) {
			if (head == tail)
				printf("%d", now);
			else
				printf("%d ", now);
		}
		if (T[now].Left != Null) {
			myQueue[tail] = T[now].Left;
			tail++;
		}
		if (T[now].Right != Null) {
			myQueue[tail] = T[now].Right;
			tail++;
		}
	}
}
int main()
{
	Tree R;
	R = BuildTree(T);
	travel(R);
	return 0;
}