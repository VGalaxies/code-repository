#include<iostream>
using namespace std;
int Pow_1(int a, int b)
{ //������a^b �����Ӷ�	log(b)
	if (b == 0)
		return 1;
	if (b & 1) { //b������
		return a * Pow_1(a, b - 1);
	}
	else {
		int t = Pow_1(a, b / 2); return t * t;
	}
}
int Pow_2(int a, int b)
{	//������a^b �����Ӷ�	log(b)
	int result = 1;
	int base = a;
	while (b) {
		if (b & 1)
			result *= base;
		base *= base;
		b >>= 1;
	}
	return result;
}
int main()
{
	cout << Pow_1(4, 6) << endl;
	cout << Pow_2(4, 6) << endl;
	return 0;
}