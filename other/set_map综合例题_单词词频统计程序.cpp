#include <iostream> 
#include <set> 
#include <map> 
#include <string> 
using namespace std; 
struct Word {
	int times; 
	string wd;
};
struct Rule {
	bool operator () (const Word& w1, const Word& w2) const {
		if (w1.times != w2.times)
			return w1.times > w2.times;
		else
			return w1.wd < w2.wd;
	}
};
int main()
{
	string s; 
	set<Word, Rule> st; 
	map<string, int> mp; 
	while (cin >> s)//ÓÃCtrl+Z½áÊø
		++mp[s];//Ò»¼ıË«µñ
	for (map<string, int>::iterator i = mp.begin(); i != mp.end(); ++i) {
		Word tmp;
		tmp.wd = i->first; 
		tmp.times = i->second; 
		st.insert(tmp);
	}
	for (set<Word, Rule>::iterator i = st.begin(); i != st.end(); ++i)
		cout << i->wd << " " << i->times << endl;
	return 0;
}