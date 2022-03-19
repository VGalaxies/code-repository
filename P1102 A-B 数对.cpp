#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n, c;
int ori[200010];
long long int res = 0;
int left_bound(int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ori[mid] < target)
            left = mid + 1;
        else if (ori[mid] > target)
            right = mid - 1;
        else if (ori[mid] == target)
            // 别返回，收紧右边界，锁定左侧边界
            right = mid - 1;
    }
    if (right + 1 >= n)
        return -1;
    return right + 1;
}
int right_bound(int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ori[mid] < target)
            left = mid + 1;
        else if (ori[mid] > target)
            right = mid - 1;
        else if (ori[mid] == target) 
            // 别返回，收紧左边界，锁定右侧边界
            left = mid + 1;
    }
    if (ori[right] != target)
        return -1;
    return right;
}
int main() {
	cin >> n >> c;
    for (int i = 0; i < n; ++i)
		cin >> ori[i];
	sort(ori, ori + n);
    for (int i = 0; i < n; ++i) {
        int L = left_bound(ori[i] + c);
        int R = right_bound(ori[i] + c);
        if (L >= 0 && R >= 0)
            res += R - L + 1;
    }
    cout << res;
}