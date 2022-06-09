#include<iostream>
#include<set>
#include<map>
#include <algorithm>
using namespace std;
map<int, set<int>> ori;
int n;
int main() {
	cin >> n;
	set<int> st;
	st.insert(1);
	ori.insert(make_pair(1000000000, st));
	int id, strength;
	for (int i = 0; i < n; ++i) {
		cin >> id >> strength;
		if (i == 0) {
			printf("%d %d\n", id, 1);
		}
		else {
			map<int, set<int>>::iterator p = ori.find(strength);
			if (p != ori.end())
				printf("%d %d\n", id, *p->second.begin());
			else {
				map<int, set<int>>::iterator upper = ori.upper_bound(strength);
				map<int, set<int>>::iterator lower = ori.lower_bound(strength);
				if(lower!=ori.begin())
					lower--;
				if (upper->first - strength < strength - lower->first)
					printf("%d %d\n", id, *upper->second.begin());
				else if (upper->first - strength > strength - lower->first)
					printf("%d %d\n", id, *lower->second.begin());
				else {
					if (*upper->second.begin() < *lower->second.begin())
						printf("%d %d\n", id, *upper->second.begin());
					else
						printf("%d %d\n", id, *lower->second.begin());
				}
			}
		}
		ori[strength].insert(id);
	}
}