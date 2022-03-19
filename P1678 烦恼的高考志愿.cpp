#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int m, n;
int campus[100010];
int stu[100010];
int left_bound(int target) {
    int left = 0, right = m - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (campus[mid] < target)
            left = mid + 1;
        else if (campus[mid] > target)
            right = mid - 1;
        else if (campus[mid] == target)
            // �𷵻أ��ս��ұ߽磬�������߽�
            right = mid - 1;
    }
    return left;
}
int right_bound(int target) {
    int left = 0, right = m - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (campus[mid] < target)
            left = mid + 1;
        else if (campus[mid] > target)
            right = mid - 1;
        else if (campus[mid] == target)
            // �𷵻أ��ս���߽磬�����Ҳ�߽�
            left = mid + 1;
    }
    return right;
}
int res = 0;
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		cin >> campus[i];
	for (int i = 0; i < n; ++i)
		cin >> stu[i];
	sort(campus, campus + m);
    for (int i = 0; i < n; ++i) 
    {//��left_bound��right_bound�����
        int R = left_bound(stu[i]);
        int L = right_bound(stu[i]);
        if (R >= m)
            res += abs(campus[L] - stu[i]);
        else if (L < 0)
            res += abs(campus[R] - stu[i]);
        else
            res += min(abs(stu[i] - campus[R]), abs(campus[L] - stu[i]));
    }
    cout << res;     
}