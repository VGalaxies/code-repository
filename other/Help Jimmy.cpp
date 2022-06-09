#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
struct block
{
	int left;
	int right;
	int height;
};
block ori[1010];
struct Rule
{ 
	bool operator() (const block& s1, const block& s2) const {
		return s1.height > s2.height;
	}
};
int leftmin[1010];
int rightmin[1010];

int N, X, Y, MAX;

int left_min(int);
int right_min(int);

int left_min(int i)
{
	int tmp = -1;
	for (int j = i + 1; j <= N; ++j)
	{
		if (ori[j].left <= ori[i].left && ori[j].right >= ori[i].left)
		{
			tmp = j;
			break;
		}
	}
	if (tmp < 0)
	{
		if (ori[i].height <= MAX)
			return ori[i].height;
		else
			return INT_MAX;
	}
	else
	{
		if (ori[i].height - ori[tmp].height <= MAX)
		{
			int left = ori[i].left - ori[tmp].left + left_min(tmp);
			int right = ori[tmp].right - ori[i].left + right_min(tmp);
			return ori[i].height - ori[tmp].height + min(left, right);
		}
		else
			return INT_MAX;
	}
}
int right_min(int i)
{
	int tmp = -1;
	for (int j = i + 1; j <= N; ++j)
	{
		if (ori[j].left <= ori[i].right && ori[j].right >= ori[i].right)
		{
			tmp = j;
			break;
		}
	}
	if (tmp < 0)
	{
		if (ori[i].height <= MAX)
			return ori[i].height;
		else
			return INT_MAX;
	}
	else
	{
		if (ori[i].height - ori[tmp].height <= MAX)
		{
			int left = ori[i].right - ori[tmp].left + left_min(tmp);
			int right = ori[tmp].right - ori[i].right + right_min(tmp);
			return ori[i].height - ori[tmp].height + min(left, right);
		}
		else
			return INT_MAX;
	}
}
int main()
{
	cin >> N >> X >> Y >> MAX;
	for (int i = 1; i <= N; ++i)
		cin >> ori[i].left >> ori[i].right >> ori[i].height;
	sort(ori + 1, ori + N + 1, Rule());
	ori[0].left = X;
	ori[0].right = X;
	ori[0].height = Y;

	leftmin[N] = ori[N].height;
	rightmin[N] = ori[N].height;

	cout << left_min(0);
	return 0;
}