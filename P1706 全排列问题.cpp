#include<iostream>
#include<iomanip>
using namespace std;
const int N = 10;
int n;
bool vis[N];  // 访问标记数组
int a[N];     // 排列数组，按顺序储存当前搜索结果
void dfs(int step) {
    if (step == n + 1) {  // 边界
        for (int i = 1; i <= n; i++) {
            cout << setw(5) << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            a[step] = i;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
    return;
}
int main() {
    cin >> n;
    dfs(1);
}