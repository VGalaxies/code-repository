#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;
int n, k;

// 套回溯算法模板
void backtrack(int n, int k, int start, vector<int>& track) {
    // 到达叶子节点才更新 res
    if (k == track.size()) {
        res.push_back(track);
        return;
    }
    // i 从 start 开始递增
    for (int i = start; i <= n; i++) {
        // 做选择
        track.push_back(i);
        // 递归回溯
        backtrack(n, k, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}

/* 主函数 */
vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) return res;
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

int main() {
    cin >> n >> k;
    res = combine(n, k);
}