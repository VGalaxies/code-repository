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
    //插入元素
    mulmap.insert(make_pair("abc", 2));
    mulmap.insert(make_pair("abc", 3));
    mulmap.insert(make_pair("bcd", 5));
    mulmap.insert(make_pair("bcd", 7));

    for (mulit mt = mulmap.begin(); mt != mulmap.end(); mt++) {
        cout << mt->first << " " << mt->second << endl;
    }
    /*方式1：最麻烦的方式：
    (1)通过iter=find()找到某个键对应元素的迭代器，如果该键值对应多个值，则返回指向第一个元素的迭代器。
    (2)通过cn=count()返回对应键元素的个数
    (3)以迭代器iter为起始位置,遍历cn次
    */
    cout << "find count 方式：" << endl;
    mulit mb = mulmap.find("abc");
    mstype mt = mulmap.count("abc");
    for (mstype tt = 0; tt < mt; tt++, mb++) {
        cout << mb->first << " " << mb->second << endl;
    }
    /*方式2：upper_bound和lower_bound方式
    通过lower_bound和upper_bound获取指向一个键对应元素的迭代器范围，其中
    lower_bound返回指向键对应的第一个元素的迭代器位置
    upper_bound返回指向这个键对应的最后一个元素的下一个位置的迭代器
    */
    cout << "upper_bound lower_bound 方式：" << endl;
    mulit lower = mulmap.lower_bound("bcd");
    mulit upper = mulmap.upper_bound("bcd");
    for (mulit tm = lower; tm != upper; tm++) {
        if(tm->second==7)
            cout << tm->first << " " << tm->second << endl;
    }
    /*方式3：直接用equal_range方法返回用pair封装的两个迭代器，两个迭代器类似于lower_bound和upper_bound返回的结果
    */
    cout << "equal_range 方法：" << endl;
    typedef pair<mulit, mulit> pmulit;
    pmulit pl = mulmap.equal_range("bcd");
    for (mulit tm = pl.first; tm != pl.second; tm++) {
        cout << mb->first << " " << mb->second << endl;
    }
}
