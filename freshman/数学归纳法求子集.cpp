#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
vector<vector<int>> ans;
int n;
vector<vector<int>> subsets(vector<int>& nums) {
    // base case������һ���ռ�
    if (nums.empty()) return { {} };
    // �����һ��Ԫ���ó���
    int n = nums.back();
    nums.pop_back();
    // �ȵݹ����ǰ��Ԫ�ص������Ӽ�
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
        // Ȼ����֮ǰ�Ľ��֮��׷��
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        arr.push_back(i + 1);
    ans = subsets(arr);
}