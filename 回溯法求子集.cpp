#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;
vector<int> arr;
int n;

/* �׻����㷨ģ�� */
void backtrack(vector<int>& nums, int start, vector<int>& track) {
    // ǰ�������λ��
    res.push_back(track);
    // �� start ��ʼ����ֹ�����ظ����Ӽ�
    for (int i = start; i < nums.size(); i++) {
        // ��ѡ��
        track.push_back(nums[i]);
        // �ݹ����
        backtrack(nums, i + 1, track);
        // ����ѡ��
        track.pop_back();
    }
}

/* ������ */
vector<vector<int>> subsets(vector<int>& nums) {
    // ��¼�߹���·��
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
