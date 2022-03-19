#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
string des;
struct node {
    string permutation;
    int steps;
    node(string _p, int  _s) :permutation(_p), steps(_s) {}
};
queue<node> q;
bool vis[362900];
int arr[3][3];
const int MAXN = 9;
int fact[MAXN] = { 1 }, P[MAXN], A[MAXN], tree[MAXN + 1];

void init(int n) {
    int i = 1;
    while (i < n) {
        fact[i] = i * fact[i - 1];
        i++;
    }
}
int lowbit(int x) { return x & -x; }
int query(int x){
    int ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
void update(int x, int d){
    for (int i = x; i < MAXN; i += lowbit(i))
        tree[i] += d;
}
int cantor(int P[]){
    int ans = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = MAXN - 1; i >= 0; i--)
    {
        A[i] = query(P[i] + 1);
        update(P[i] + 1, 1);
    }
    for (int i = 0; i < MAXN; i++)
        ans += A[i] * fact[MAXN - 1 - i];
    return ans;
}
int add_vis(string s) {
    for (int i = 0; i < MAXN; ++i)
        P[i] = s[i] - '0';
    int re = cantor(P);
    if (vis[re] == false) {
        vis[re] = true;
        return 1;
    }
    else
        return 0;
}

int MOVE[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void move(string s, int step) {
    int index = 0;
    int pos_zero_x, pos_zero_y;
    int pos_swap_x, pos_swap_y;
    string tmp(9, '0');
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = s[index++] - '0';
            if (arr[i][j] == 0) {
                pos_zero_x = i;
                pos_zero_y = j;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        pos_swap_x = pos_zero_x + MOVE[i][0];
        pos_swap_y = pos_zero_y + MOVE[i][1];
        if (pos_swap_x >= 0 && pos_swap_y >= 0 && pos_swap_x <= 2 && pos_swap_y <= 2) {
            swap(arr[pos_swap_x][pos_swap_y], arr[pos_zero_x][pos_zero_y]);
            int index = 0;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    tmp[index++] = arr[i][j] + '0';
            if (add_vis(tmp))
                q.push(node(tmp, step + 1));
            swap(arr[pos_swap_x][pos_swap_y], arr[pos_zero_x][pos_zero_y]);
        }
    }
}
int main() {
    string ori = "123804765";
	cin >> des;
    q.push(node(des, 0));
    init(MAXN);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        int step = tmp.steps;
        string snow = tmp.permutation;
        if (snow == ori) {
            cout << step;
            return 0;
        }
        add_vis(snow);
        move(snow, step);
    }
}