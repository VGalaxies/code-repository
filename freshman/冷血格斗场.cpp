//配合冷血格斗场_test.cpp测试
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
	mp.insert(make_pair(member1.strength, member1.id));//第一位会员
	cout << member1.id << " " << facer.id << endl;
	if (n >= 2)
	{
		for (int i = 2; i <= n; ++i)
		{
			Info member;
			cin >> member.id >> member.strength;
			mp.insert(make_pair(member.strength, member.id));
			multimap<int, int>::iterator p_lower = mp.lower_bound(member.strength);
			multimap<int, int>::iterator p_upper = mp.upper_bound(member.strength);
			multimap<int, int>::iterator p;//找该用户
			for (multimap<int, int>::iterator tmp = p_lower; tmp != p_upper; ++tmp)
			{
				if (tmp->second == member.id)
					p = tmp;
			}
			multimap<int, int>::iterator p_begin = mp.begin();//实力值最低
			multimap<int, int>::iterator p_end = mp.end(); p_end--;//实力值最高
			if (p->first == p_begin->first)//该会员实力值与最低的一样低
			{
				multimap<int, int>::iterator q = ++p;//第二位会员，判断该会员是否实力值最低
				--p;
				if (p == p_begin && q->first > p->first)
					cout << member.id << " " << q->second << endl;
				else
				{
					int strength_down = p_begin->first;//记录该实力值
					int id_small = p_begin->second;//记录第一位会员id
					for (; p_begin->first == strength_down&&p_begin!=mp.end(); ++p_begin)//遍历所有最低实力值的会员
					{
						if (p_begin->second < id_small)
							id_small = p_begin->second;//更新最小id
					}
					cout << member.id << " " << id_small << endl;
				}
			}
			else if (p->first == p_end->first)
			{
				multimap<int, int>::iterator r = --p;//倒数二位会员，判断该会员是否实力值最高
				++p;
				if (p == p_end && r->first < p->first)
					cout << member.id << " " << r->second << endl;
				else
				{
					int strength_up = p_end->first;//记录该实力值
					int id_small = p_end->second;//记录最后一位会员id
					for (; p_end->first == strength_up && p_end != mp.end(); --p_end)//遍历所有最高实力值的会员
					{
						if (p_end->second < id_small)
							id_small = p_begin->second;//更新最小id
					}
					cout << member.id << " " << id_small << endl;
				}
			}
			else
			{
				multimap<int, int>::iterator p_up = mp.upper_bound(member.strength);//member后一位
				multimap<int, int>::iterator p_down = --p;//member前一位
				if ((p_up->first - member.strength) < (member.strength - p_down->first))
					cout << member.id << " " << p_up->second << endl;
				else if((p_up->first - member.strength) > (member.strength - p_down->first))
					cout << member.id << " " << p_down->second << endl;
				else//member的前后实力值差距相同
				{
					if (p_up->first - member.strength != 0)//member的前后实力值与member不同
					{
						if(p_up->second < p_down->second)
							cout << member.id << " " << p_up->second << endl;
						else
							cout << member.id << " " << p_down->second << endl;
					}
					else//member的前后实力值与member相同
					{
						int strength = member.strength;
						int id_small = (p_up->second < p_down->second) ? (p_up->second) : (p_down->second);//得到member前后id的最小值
						for (; p_down->first == strength&&p_down!=mp.begin(); --p_down);
						++p_down;
						for (; p_down->first == strength && p_down != mp.end(); ++p_down)//开始遍历
						{
							if (p_down->second < id_small)
								id_small = p_down->second;
						}
						cout << member.id << " " << id_small << endl;
					}
				}
			}
		}
	}
	return 0;
}