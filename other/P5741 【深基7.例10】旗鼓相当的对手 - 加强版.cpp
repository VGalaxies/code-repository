#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct student
{
	string name;
	int s1;
	int s2;
	int s3;
};
student s[1010];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i].name >> s[i].s1 >> s[i].s2  >> s[i].s3;
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			int ans = abs(s[i].s1 - s[j].s1);//每一门分数相减
			int ans1 = abs(s[i].s2 - s[j].s2);
			int ans2 = abs(s[i].s3 - s[j].s3);
			int ans3 = abs(s[i].s1 + s[i].s2 + s[i].s3 - s[j].s1 - s[j].s2 - s[j].s3);//总分相减
			if (ans <= 5 && ans1 <= 5 && ans2 <= 5 && ans3 <= 10) 
			{//判断是否符合旗鼓相当的对手
				if (s[i].name > s[j].name)//判断字典序
					cout << s[j].name << " " << s[i].name << "\n";
				else cout << s[i].name << " " << s[j].name << "\n";
			}
		}
	}
	return 0;
}