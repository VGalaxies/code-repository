#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

inline int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c>'9') c = getchar();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x;
}

int N, M;
int a[maxn], b[maxn];

inline int lowbit(const int& x) { return x & -x; }

void updata(int x) {
    while (x <= N) {
        b[x] = a[x];
        int lx = lowbit(x);
        for (int i = 1; i < lx; i <<= 1) {
            b[x] = max(b[x], b[x - i]);
        }
        x += lowbit(x);
    }
}

int query(int x, int y) {
    int ans = 0;
    while (y >= x) {
        ans = max(ans, a[y]), --y;
        while (y - lowbit(y) >= x) {
            ans = max(ans, b[y]);
            y -= lowbit(y);
        }
    }
    return ans;
}

int main() {
    //ios::sync_with_stdio(false);
    while (~scanf("%d%d", &N, &M)) {
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= N; ++i) a[i] = read(), updata(i);
        while (M--) {
            char c;
            int A, B;
            scanf("\n%c%d%d", &c, &A, &B);
            if (c == 'Q') printf("%d\n", query(A, B));
            else if (c == 'U') {
                a[A] = B;
                updata(A);
            }
        }
    }
}