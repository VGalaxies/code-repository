/*
����
Ϊ��ӭ��08��İ��˻ᣬ�ô�Ҹ����˽���ָ��˶���facer�¿���һ����Ѫ�񶷳���
�񶷳�ʵ�л�Ա�ƣ����������Ļ�Ա����Ҫ�����ѣ���ֻҪͬһ���ϻ�Ա��һ����������֤���Լ���ʵ����

���Ǽ���񶷵�ʵ��������һ����������ʾ����Ϊʵ��ֵ��
���⣬ÿ���˶���һ��Ψһ��id��Ҳ��һ����������
Ϊ��ʹ�ñ������ÿ���ÿһ���¶�Ա����ѡ������ʵ����Ϊ�ӽ����˱�����
������˫����ʵ��ֵ֮��ľ���ֵԽСԽ�ã�����������˵�ʵ��ֵ���������ͬ��
������ѡ����������Ǹ�����Ȼ��Ű�˱ر�Ű�ã���

���ҵ��ǣ�Facerһ��С�İѱ�����¼Ū���ˣ��������������Ż�Ա��ע���¼��
���������facer�ָ�������¼������ʱ��˳���������ÿ������˫����id��
����
��һ��һ����n(0 < n <=100000)����ʾ�񶷳������Ļ�Ա����������facer����
�Ժ�n��ÿһ������������������ʱ�������Ա��id��ʵ��ֵ��
һ��ʼ��facer�����ǻ�Ա��idΪ1��ʵ��ֵ1000000000�����뱣֤���˵�ʵ��ֵ��ͬ��
���
N�У�ÿ����������Ϊÿ������˫����id�����ֵ�idд��ǰ�档
��������
3
2 1
3 3
4 2
�������
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
				multimap<int, int>::iterator p_up = mp.upper_bound(member.strength);//member��һλ
				multimap<int, int>::iterator p_down = --p;//memberǰһλ
				if ((p_up->first - member.strength) < (member.strength - p_down->first))
					printf("%d %d\n", member.id, p_up->second);
				else
					printf("%d %d\n", member.id, p_down->second);
			}	
		}
	}
	return 0;
}