#include<iostream>
#include<string>
using namespace std;
const int LEN = 120;
int a[LEN];
int b[LEN];
int c[LEN];
int n;
inline int length(int a[]) {
    int len = LEN - 1;
    while (a[len] == 0)
        len--;
    return len + 1;
}
inline void clear(int a[]) {
    for (int i = 0; i < LEN; ++i)
        a[i] = 0;
}
void read(int a[]) {
    string s;
    cin >> s;
    clear(a);
    int len = s.size();
    for (int i = 0; i < len; ++i)
        a[len - i - 1] = s[i] - '0';
}
void mul(int a[], int b[], int c[]) {
    clear(c);
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j <= i; ++j)
            c[i] += a[j] * b[i - j];
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
void trans(int a[], int c[]) {
    int len = length(c);
    for (int i = 0; i < len; ++i)
        a[i] = c[i];
}
void print(int a[]) {
    int len = length(a);
    for (int i = len - 1; i >= 0; --i)
        cout << a[i];
}
int main() {
    cin >> n;
    read(a);
    for (int i = 1; i < n; ++i) {
        read(b);
        mul(a, b, c);
        trans(a, c);
    }
    print(a);
}