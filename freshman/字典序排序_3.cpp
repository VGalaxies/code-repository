#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string word[10010];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> word[i];
	sort(word, word + n);
	for (int i = 0; i < n; ++i)
		cout << word[i] << " ";
	return 0;
}