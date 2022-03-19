#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;
int n, k;

// �׻����㷨ģ��
void backtrack(int n, int k, int start, vector<int>& track) {
    // ����Ҷ�ӽڵ�Ÿ��� res
    if (k == track.size()) {
        res.push_back(track);
        return;
    }
    // i �� start ��ʼ����
    for (int i = start; i <= n; i++) {
        // ��ѡ��
        track.push_back(i);
        // �ݹ����
        backtrack(n, k, i + 1, track);
        // ����ѡ��
        track.pop_back();
    }
}

/* ������ */
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