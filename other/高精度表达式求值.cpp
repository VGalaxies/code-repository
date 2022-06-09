#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cassert>
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define per(i,n,k) for(int i=n;i>=k;i--)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define re return
#define se second
#define fi first
using namespace std;

struct BigInteger {
    typedef unsigned long long LL;

    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger& clean() { while (!s.back() && s.size() > 1)s.pop_back(); return *this; }
    BigInteger(LL num = 0) { *this = num; }
    BigInteger(string s) { *this = s; }
    BigInteger& operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger& operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }

    BigInteger operator + (const BigInteger& b) const {
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) x += s[i];
            if (i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) const {
        assert(b <= *this); // 减数不能大于被减数
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = s[i] + g;
            if (i < b.s.size()) x -= b.s[i];
            if (x < 0) { g = -1; x += BASE; }
            else g = 0;
            c.s.push_back(x);
        }
        return c.clean();
    }
    BigInteger operator * (const BigInteger& b) const {
        int i, j; LL g;
        vector<LL> v(s.size() + b.s.size(), 0);
        BigInteger c; c.s.clear();
        for (i = 0; i < s.size(); i++) for (j = 0; j < b.s.size(); j++) v[i + j] += LL(s[i]) * b.s[j];
        for (i = 0, g = 0; ; i++) {
            if (g == 0 && i >= v.size()) break;
            LL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
    BigInteger operator / (const BigInteger& b) const {
        assert(b > 0);  // 除数必须大于0
        BigInteger c = *this;       // 商:主要是让c.s和(*this).s的vector一样大
        BigInteger m;               // 余数:初始化为0
        for (int i = s.size() - 1; i >= 0; i--) {
            m = m * BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b * c.s[i];
        }
        return c.clean();
    }
    BigInteger operator % (const BigInteger& b) const { //方法与除法相同
        BigInteger c = *this;
        BigInteger m;
        for (int i = s.size() - 1; i >= 0; i--) {
            m = m * BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b * c.s[i];
        }
        return m;
    }

    int bsearch(const BigInteger& b, const BigInteger& m) const {
        int L = 0, R = BASE - 1, x;
        while (1) {
            x = (L + R) >> 1;
            if (b * x <= m) { if (b * (x + 1) > m) return x; else L = x; }
            else R = x;
        }
    }
    BigInteger& operator += (const BigInteger& b) { *this = *this + b; return *this; }
    BigInteger& operator -= (const BigInteger& b) { *this = *this - b; return *this; }
    BigInteger& operator *= (const BigInteger& b) { *this = *this * b; return *this; }
    BigInteger& operator /= (const BigInteger& b) { *this = *this / b; return *this; }
    BigInteger& operator %= (const BigInteger& b) { *this = *this % b; return *this; }

    bool operator < (const BigInteger& b) const {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator >(const BigInteger& b) const { return b < *this; }
    bool operator<=(const BigInteger& b) const { return !(b < *this); }
    bool operator>=(const BigInteger& b) const { return !(*this < b); }
    bool operator!=(const BigInteger& b) const { return b < *this || *this < b; }
    bool operator==(const BigInteger& b) const { return !(b < *this) && !(b > * this); }
};

ostream& operator << (ostream& out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

istream& operator >> (istream& in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}
stack<BigInteger> si;
stack<char> sc;
vector<BigInteger> vc;
bool isnum[1005];
bool flag = 0;
BigInteger pow(BigInteger a, BigInteger b) { BigInteger base = a, ans = 1; while (b != 0) { if (b % 2 == 1)ans *= base; base *= base; b /= 2; }return ans; }
BigInteger clas(char c)//符号优先级 
{
    if (c == '(' || c == ')') re 0;
    if (c == '+' || c == '-') re 1;
    if (c == '*' || c == '/') re 2;
    if (c == '^') re 3;
    re 4;
}
BigInteger cal(BigInteger a, BigInteger b, BigInteger c)//符号求值 
{
    BigInteger ans = 1;
    if (c == '+') re a + b;
    if (c == '-') re b - a;
    if (c == '*') re a* b;
    if (c == '/') re b / a;
    re pow(b, a);
}
int main()
{
    string s; cin >> s;
    s = "(" + s + ")";//可以用来防止栈为空找top时的溢出情况 
    int n = (int)s.size();
    rep(i, 0, n - 1)
    {
        if (s[i] == '(')//左括号直接压入 
        {
            sc.push(s[i]);
            continue;
        }
        if (s[i] == ')')//找到右括号将栈清空到左括号为止 
        {
            char c = sc.top(); sc.pop();
            while (c != '(')
            {
                vc.pb(c);
                c = sc.top(); sc.pop();
            }
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')//数字 
        {
            BigInteger sum = 0;
            while (s[i] >= '0' && s[i] <= '9')
                sum = sum * 10 + s[i++] - '0';
            if (flag)
                sum = BigInteger(-1) * sum, flag = 0;
            vc.pb(sum);
            isnum[vc.size() - 1] = 1;
            i--; continue;
        }
        if (s[i] == '-' && (clas(s[i - 1]) != 4 && s[i - 1] != ')'))
        {
            flag = 1;
            continue;
        }
        while (!sc.empty() && clas(s[i]) <= clas(sc.top()))//如果是符号就找到第一个优先级比他小的 
            vc.pb(sc.top()), sc.pop();
        sc.push(s[i]);
    }
    while (!sc.empty())//清空栈 
        vc.pb(sc.top()), sc.pop();
    rep(i, 0, vc.size() - 1)//根据后缀表达式求值 
    {
        if (!isnum[i])
        {
            BigInteger a = si.top(); si.pop();
            BigInteger b = si.top(); si.pop();
            BigInteger ans = cal(a, b, vc[i]);
            si.push(ans);
        }
        else
            si.push(vc[i]);
    }
    cout << si.top();
    return 0;
}