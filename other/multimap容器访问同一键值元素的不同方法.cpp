#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iterator>
using namespace std;
int main()
{
    typedef multimap<string, int>::size_type mstype;
    typedef multimap<string, int>::iterator mulit;
    multimap<string, int> mulmap;
    //����Ԫ��
    mulmap.insert(make_pair("abc", 2));
    mulmap.insert(make_pair("abc", 3));
    mulmap.insert(make_pair("bcd", 5));
    mulmap.insert(make_pair("bcd", 7));

    for (mulit mt = mulmap.begin(); mt != mulmap.end(); mt++) {
        cout << mt->first << " " << mt->second << endl;
    }
    /*��ʽ1�����鷳�ķ�ʽ��
    (1)ͨ��iter=find()�ҵ�ĳ������ӦԪ�صĵ�����������ü�ֵ��Ӧ���ֵ���򷵻�ָ���һ��Ԫ�صĵ�������
    (2)ͨ��cn=count()���ض�Ӧ��Ԫ�صĸ���
    (3)�Ե�����iterΪ��ʼλ��,����cn��
    */
    cout << "find count ��ʽ��" << endl;
    mulit mb = mulmap.find("abc");
    mstype mt = mulmap.count("abc");
    for (mstype tt = 0; tt < mt; tt++, mb++) {
        cout << mb->first << " " << mb->second << endl;
    }
    /*��ʽ2��upper_bound��lower_bound��ʽ
    ͨ��lower_bound��upper_bound��ȡָ��һ������ӦԪ�صĵ�������Χ������
    lower_bound����ָ�����Ӧ�ĵ�һ��Ԫ�صĵ�����λ��
    upper_bound����ָ���������Ӧ�����һ��Ԫ�ص���һ��λ�õĵ�����
    */
    cout << "upper_bound lower_bound ��ʽ��" << endl;
    mulit lower = mulmap.lower_bound("bcd");
    mulit upper = mulmap.upper_bound("bcd");
    for (mulit tm = lower; tm != upper; tm++) {
        if(tm->second==7)
            cout << tm->first << " " << tm->second << endl;
    }
    /*��ʽ3��ֱ����equal_range����������pair��װ������������������������������lower_bound��upper_bound���صĽ��
    */
    cout << "equal_range ������" << endl;
    typedef pair<mulit, mulit> pmulit;
    pmulit pl = mulmap.equal_range("bcd");
    for (mulit tm = pl.first; tm != pl.second; tm++) {
        cout << mb->first << " " << mb->second << endl;
    }
}
