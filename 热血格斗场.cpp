/*
描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家热血格斗场。
格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

我们假设格斗的实力可以用一个正整数表示，成为实力值。
另外，每个人都有一个唯一的id，也是一个正整数。
为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，
即比赛双方的实力值之差的绝对值越小越好，如果有两个人的实力值与他差别相同，
则他会选择比他弱的那个（显然，虐人必被虐好）。

不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。
现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。
输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。
以后n行每一行两个数，按照入会的时间给出会员的id和实力值。
一开始，facer就算是会员，id为1，实力值1000000000。输入保证两人的实力值不同。
输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。
样例输入
3
2 1
3 3
4 2
样例输出
2 1
3 2
4 2
*/
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iterator>
using namespace std;
struct Info
{
	int strength;
	int id;
};
int main()
{
	multimap<int, int> mp;
	Info facer;
	facer.id = 1;
	facer.strength = 1000000000;
	mp.insert(make_pair(facer.strength, facer.id));
	int n;
	cin >> n;
	Info member1;
	cin >> member1.id >> member1.strength;
	mp.insert(make_pair(member1.strength, member1.id));
	printf("%d %d\n", member1.id, facer.id);
	if (n >= 2)
	{
		for (int i = 2; i <= n; ++i)
		{
			Info member;
			cin >> member.id >> member.strength;
			mp.insert(make_pair(member.strength, member.id));
			multimap<int, int>::iterator p = mp.find(member.strength);
			multimap<int, int>::iterator p_begin = mp.begin();
			multimap<int, int>::iterator p_end = mp.end();
			p_end--;
			if (p == p_begin)
			{
				multimap<int, int>::iterator q = ++p;
				printf("%d %d\n", member.id, q->second);
			}
			else if (p == p_end)
			{
				multimap<int, int>::iterator r = --p;
				printf("%d %d\n", member.id, r->second);
			}
			else
			{
				multimap<int, int>::iterator p_up = mp.upper_bound(member.strength);//member后一位
				multimap<int, int>::iterator p_down = --p;//member前一位
				if ((p_up->first - member.strength) < (member.strength - p_down->first))
					printf("%d %d\n", member.id, p_up->second);
				else
					printf("%d %d\n", member.id, p_down->second);
			}	
		}
	}
	return 0;
}