#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string tmp;
struct Arr {
	int arr[55];
	int len;
	Arr() {
		memset(arr, 0, sizeof(arr));
		len = 1;
	}
	void mymax() {
		this->len = 55;
	}
	void reverse() {
		for (int i = 0; i < len/2; ++i) {
			int tmp = this->arr[i];
			this->arr[i] = this->arr[len - 1 - i];
			this->arr[len - 1 - i] = tmp;
		}
	}
	Arr(string s, int st,int ed) {
		memset(arr, 0, sizeof(arr));
		len = ed - st + 1;
		for (int i = st; i <= ed; ++i)
			arr[i - st] = s[i] - '0';
	}
	friend bool operator<(const Arr& a, const Arr& b) {
		int len_a = a.len;
		int len_b = b.len;
		if (len_a < len_b)
			return true;
		else if (len_a > len_b)
			return false;
		else {
			for (int i = 0; i < len_a; ++i) {
				if (a.arr[i] < b.arr[i])
					return true;
				else if (a.arr[i] > b.arr[i])
					return false;
			}
			return true;
		}
	}
	friend Arr operator+(Arr a, Arr b) {
		Arr ans;
		int len_a = a.len;
		int len_b = b.len;
		a.reverse();
		b.reverse();
		int len = max(len_a, len_b);
		int i = 0;
		for (i; i < len; ++i) {
			ans.arr[i] += a.arr[i] + b.arr[i];
			if (ans.arr[i] >= 10) {
				ans.arr[i + 1] += 1;
				ans.arr[i] -= 10;
			}
		}
		if (ans.arr[i])
			ans.len = len + 1;

		else
			ans.len = len;
		ans.reverse();
		return ans;
	}
	friend ostream& operator << (ostream& os, const Arr& a) {
		int len = a.len;
		for (int i = 0; i < len; ++i)
			os << a.arr[i];
		os << endl;
		return os;
	}
};
Arr dp[55][55];
Arr sum[55][55];
void init_sum(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			sum[i][j] = Arr(tmp, i, j);
		}
	}
}
void DP(int m, int n) {//m个加号，n位数
	if (m == 0) {
		dp[m][n] = sum[0][n - 1];
	}
	else {
		Arr tmp;
		tmp.mymax();
		for (int i = m; i <= n - 1; ++i) {
			Arr now = dp[m - 1][i] + sum[i][n - 1];
			if (now < tmp)
				tmp = now;
		}
		dp[m][n] = tmp;
	}
}
int main()
{
	int m, len;
	while (cin >> m >> tmp) {
		len = tmp.size();
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		init_sum(len);
		for (int i = 0; i <= m; ++i) {
			for (int j = i + 1; j <= len; ++j) {
				DP(i, j);
			}
		}
		cout << dp[m][len];
	}
	return 0;
}