#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;
vector<int> arr;
int n;

/* 套回溯算法模板 */
void backtrack(vector<int>& nums, int start, vector<int>& track) {
    // 前序遍历的位置
    res.push_back(track);
    // 从 start 开始，防止产生重复的子集
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        track.push_back(nums[i]);
        // 递归回溯
        backtrack(nums, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}

/* 主函数 */
vector<vector<int>> subsets(vector<int>& nums) {
    // 记录走过的路径
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        arr.push_back(i + 1);
    res = subsets(arr);
}
