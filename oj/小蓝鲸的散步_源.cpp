#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int leftmax[100005], rightmax[100005];
int left[100005], right[100005], h[100005];
int max = 0;
int maxx(int a, int b) {
    if (a > b) return a; else return b;
}
void search(int k, int height) {
    h[k] = height;
    if (left[k] == -1) {
        leftmax[k] = h[k];
    }
    else {
        search(left[k], height + 1);
        leftmax[k] = maxx(leftmax[left[k]], rightmax[left[k]]);
    }
    if (right[k] == -1) {
        rightmax[k] = h[k];
    }
    else {
        search(right[k], height + 1);
        rightmax[k] = maxx(rightmax[right[k]], leftmax[right[k]]);
    }
    max = maxx(max, leftmax[k] + rightmax[k] - h[k] * 2);
}
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++) {
        scanf("%d %d", &left[i], &right[i]);
    }
    search(0, 1);
    printf("%d", 2 * n - 2 - max);
}