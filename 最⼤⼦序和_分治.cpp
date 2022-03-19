#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ori[200010];
int n;
int max_3(int a, int b, int c) {
	int tmp1 = (a >= b) ? a : b;
	int tmp2 = (tmp1 >= c) ? tmp1 : c;
	return tmp2;
}
int MaxSubSum(const int a[], int L, int R) {
	int max_left, max_right;
	int max_left_border = 0, max_right_border = 0;
	int left_border = 0, right_border = 0;
	int mid;
	if (L == R) {//基准情形
		if (a[L] > 0)
			return a[L];
		else
			return 0;
	}
	mid = (L + R) / 2;
	max_left = MaxSubSum(a, L, mid);
	max_right = MaxSubSum(a, mid + 1, R);

	for (int i = mid; i >= L; --i) {
		left_border += a[i];
		if (left_border > max_left_border)
			max_left_border = left_border;
	}
	for (int i = mid + 1; i <= R; ++i) {
		right_border += a[i];
		if (right_border > max_right_border)
			max_right_border = right_border;
	}
	return max_3(max_left, max_right, max_left_border + max_right_border);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ori[i]);
	printf("%d", MaxSubSum(ori, 0, n - 1));
	return 0;
}