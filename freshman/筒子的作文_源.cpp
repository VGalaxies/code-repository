#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cctype>
using namespace std;
const int N = 210;
char s[N];
int print(int cur)
{
	int k = 0, tmp = 0;
	for (; 1;)
	{
		for (; 'a' <= s[cur] && s[cur] <= 'z'; putchar(s[cur]), ++cur);
		if (s[cur] == ']' || !s[cur]) return cur + 1;
		for (k = 0; isdigit(s[cur]); k = k * 10 + s[cur] - '0', ++cur);
		for (int i = 1; i <= k; ++i) tmp = print(cur + 1);
		cur = tmp;
	}
	return cur + 1;
}

int main(int argc, char const* argv[])
{
	scanf("%s", s + 1);
	print(1);
	return 0;
}