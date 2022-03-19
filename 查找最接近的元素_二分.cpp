#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int ori[100010];
int result[10010];
int n, m;
int search(int* a, int p) {
	int L = 0;
	int R = n - 1;
	int tmp_min = abs(p - ori[n - 1]);
	int tmp_index = n - 1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (tmp_min >= abs(p - ori[mid])) {
			if (tmp_min == abs(p - ori[mid]) && tmp_index > mid) {
				tmp_index = mid;
			}
			if (tmp_min > abs(p - ori[mid])) {
				tmp_min = abs(p - ori[mid]);
					tmp_index = mid;
			}
		}
		if (p < ori[mid])
			R = mid - 1;
		else
			L = mid + 1;
	}
	return tmp_index;

}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ori[i]);
	scanf("%d", &m);
	int cases = 0;
	while (cases<m)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		result[cases++] = search(ori, tmp);
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", ori[result[i]]);
}