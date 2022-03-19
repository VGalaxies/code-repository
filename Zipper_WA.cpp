#include<iostream>
#include<cstring>
using namespace std;
char A[250];
char B[250];
char C[500];
bool judge[500];//判断C中的字符是否被搜索过
bool output[1010];
int main()
{
	int order = 0;
	int n;
	cin >> n;
	loop:
	while (n--)
	{
		if (!order)
			cin.get();
		cin.getline(A, 201, ' ');
		cin.getline(B, 201, ' ');
		cin.getline(C, 401);
		int len_a = strlen(A);
		int len_b = strlen(B);
		int len_c = strlen(C);
		for (int i = 0; i < len_c; ++i)
			judge[i] = true;//初始化为true,可被搜索
		int i = 0, j = 0, k = 0;
		while (i < len_a && j < len_b)
		{
			int count = 0;//防死循环
			while (k < 2 * min(len_a, len_b))
			{
				if (judge[k])
				{
					if (A[i] == C[k])
					{
						judge[k] = false;
						i++;
						k++;
					}
					else
						count++;
					if (B[j] == C[k])
					{
						judge[k] = false;
						j++;
						k++;
					}
					else
						count++;
					if (count > 2 * max(len_a, len_b))//应足够足够大
					{
						output[order++]=false;
						goto loop;
					}
				}
				else
				{
					output[order++] = false;
					goto loop;
				}
			}
		}
		if (len_a == len_b)
		{
			int count = 0;
			for (int k = 0; k < len_c; ++k)
				if (!judge[k])
					count++;
			if (count == len_c)
				output[order++] = true;
			else
				output[order++] = false;
		}
		else if (len_a > len_b)
		{
			bool judge_a = true;
			for (; k < len_c; ++k, ++i)
			{
				if (A[i] != C[k])
				{
					judge_a = false;
					break;
				}
			}
			if (judge_a)
				output[order++] = true;
			else
				output[order++] = false;
		}
		else
		{
			bool judge_b = true;
			for (; k < len_c; ++k, ++j)
			{
				if (B[j] != C[k])
				{
					judge_b = false;
					break;
				}
			}
			if (judge_b)
				output[order++] = true;
			else
				output[order++] = false;
		}
	}
	for (int i = 0; i < order; ++i)
	{
		if (output[i])
			cout << "Data set " << i << ": yes" << endl;
		else
			cout << "Data set " << i << ": no" << endl;
	}
	return 0;
}