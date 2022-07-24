//�����Ѫ�񶷳�_test.cpp����
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
	mp.insert(make_pair(member1.strength, member1.id));//��һλ��Ա
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
			multimap<int, int>::iterator p;//�Ҹ��û�
			for (multimap<int, int>::iterator tmp = p_lower; tmp != p_upper; ++tmp)
			{
				if (tmp->second == member.id)
					p = tmp;
			}
			multimap<int, int>::iterator p_begin = mp.begin();//ʵ��ֵ���
			multimap<int, int>::iterator p_end = mp.end(); p_end--;//ʵ��ֵ���
			if (p->first == p_begin->first)//�û�Աʵ��ֵ����͵�һ����
			{
				multimap<int, int>::iterator q = ++p;//�ڶ�λ��Ա���жϸû�Ա�Ƿ�ʵ��ֵ���
				--p;
				if (p == p_begin && q->first > p->first)
					cout << member.id << " " << q->second << endl;
				else
				{
					int strength_down = p_begin->first;//��¼��ʵ��ֵ
					int id_small = p_begin->second;//��¼��һλ��Աid
					for (; p_begin->first == strength_down&&p_begin!=mp.end(); ++p_begin)//�����������ʵ��ֵ�Ļ�Ա
					{
						if (p_begin->second < id_small)
							id_small = p_begin->second;//������Сid
					}
					cout << member.id << " " << id_small << endl;
				}
			}
			else if (p->first == p_end->first)
			{
				multimap<int, int>::iterator r = --p;//������λ��Ա���жϸû�Ա�Ƿ�ʵ��ֵ���
				++p;
				if (p == p_end && r->first < p->first)
					cout << member.id << " " << r->second << endl;
				else
				{
					int strength_up = p_end->first;//��¼��ʵ��ֵ
					int id_small = p_end->second;//��¼���һλ��Աid
					for (; p_end->first == strength_up && p_end != mp.end(); --p_end)//�����������ʵ��ֵ�Ļ�Ա
					{
						if (p_end->second < id_small)
							id_small = p_begin->second;//������Сid
					}
					cout << member.id << " " << id_small << endl;
				}
			}
			else
			{
				multimap<int, int>::iterator p_up = mp.upper_bound(member.strength);//member��һλ
				multimap<int, int>::iterator p_down = --p;//memberǰһλ
				if ((p_up->first - member.strength) < (member.strength - p_down->first))
					cout << member.id << " " << p_up->second << endl;
				else if((p_up->first - member.strength) > (member.strength - p_down->first))
					cout << member.id << " " << p_down->second << endl;
				else//member��ǰ��ʵ��ֵ�����ͬ
				{
					if (p_up->first - member.strength != 0)//member��ǰ��ʵ��ֵ��member��ͬ
					{
						if(p_up->second < p_down->second)
							cout << member.id << " " << p_up->second << endl;
						else
							cout << member.id << " " << p_down->second << endl;
					}
					else//member��ǰ��ʵ��ֵ��member��ͬ
					{
						int strength = member.strength;
						int id_small = (p_up->second < p_down->second) ? (p_up->second) : (p_down->second);//�õ�memberǰ��id����Сֵ
						for (; p_down->first == strength&&p_down!=mp.begin(); --p_down);
						++p_down;
						for (; p_down->first == strength && p_down != mp.end(); ++p_down)//��ʼ����
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