#include <iostream>
using namespace std;
bool vis[100];
int total = 0;
int ans[100];

//������
void print(int r) {
    // if(total==5) return ;
    total++;
    cout << "<" << total << ">" << endl;
    for (int i = 1; i <= r; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void search(int t, int n, int r) {
    if (t == r + 1) print(r);//ȡr��������������
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {//�ж���i����ֹ�
            ans[t] = i, vis[i] = 1;
            search(t + 1, n, r);
            vis[i] = 0;
        }
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    search(1, n, r);
    cout << total << endl;
    return 0;
}