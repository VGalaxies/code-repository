#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int base, steps;
char ori[110];
int arr[110];
int reverse_arr[110];
int carry[110];
int length(int* a) {
	int len = 0;
	while (a[len] != -1)
		len++;
	return len;
}
bool judge(int* a) {
	int len = 0;
	while (a[len] != -1)
		len++;
	for (int i = 0, j = len - 1; i < j; ++i, --j)
		if (a[i] != a[j])
			return false;
	return true;
}
void Plus(int* a, int* b) {
	memset(carry, 0, sizeof(carry));
	int len = length(a);
	int i, tmp;
	for (i = 0; i < len; ++i) {
		tmp = a[i] + b[i] + carry[i];
		if (tmp >= base) {
			tmp -= base;
			carry[i + 1] = 1;
		}
		a[i] = tmp;
	}
	if (carry[i])
		a[i] = 1;
}
int main() {
	cin >> base >> ori;
	int len = strlen(ori);
	memset(arr, -1, sizeof(arr));
	memset(reverse_arr, -1, sizeof(reverse_arr));
	if (base == 16) {
		for (int i = 0; i < len; ++i) {
			switch (ori[i]){
				case 'A':case 'a':arr[i] = 10; break;
				case 'B':case 'b':arr[i] = 11; break;
				case 'C':case 'c':arr[i] = 12; break;
				case 'D':case 'd':arr[i] = 13; break;
				case 'E':case 'e':arr[i] = 14; break;
				case 'F':case 'f':arr[i] = 15; break;
				default:arr[i] = ori[i] - '0';break;
			}
		}		
	}
	else {
		for (int i = 0; i < len; ++i)
			arr[i] = ori[i] - '0';
	}
	while (!judge(arr) && steps <= 30) {
		reverse_copy(arr, arr + length(arr), reverse_arr);
		Plus(arr, reverse_arr);
		steps++;
	}
	if (!judge(arr))
		cout << "Impossible!";
	else
		cout << "STEP=" << steps;
}