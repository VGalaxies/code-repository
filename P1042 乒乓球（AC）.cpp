#include <iostream>
using namespace std;
int info[100010];
void Tennis(int *a, int n)
{
	int win = 0;
	int lost = 0;
	for (int i = 1;; i++)
	{
		if (a[i] == 1)
			win++;
		if (a[i] == 2)
			lost++;
		if (a[i] == 0) {
			cout << win << ":" << lost << endl;
			break;
		}
		if (win - lost >= 2 || lost - win >= 2) {
			if (win >= n || lost >= n) {
				cout << win << ":" << lost << endl;
				win = 0;
				lost = 0;
			}
		}
	}
}
int main(){
	char s;
	for (int i = 1; cin >> s && s != 'E'; i++){
		if (s == 'W')
			info[i] = 1;
		else 
			info[i] = 2;
	}
	Tennis(info, 11);
	cout << endl;
	Tennis(info, 21);
	return 0;
}