/*
�ݹ�
����д����ʽ��������Ϊ�գ��Ϳ��Բ��ùܿ������ˣ�
��i��ƻ������k��������ŷ������� f(i,k)����
k > i ʱ��	
f(i,k) = f(i,i)
k <= i ʱ���ܷŷ� = ������Ϊ�յķŷ�+û����Ϊ�յķŷ�
f(i,k) = f(i,k-1) + f(i-k,k)
�߽�����������
*/
#include<iostream>
using namespace std;
#include <iostream>
using namespace std;
int f(int m, int n) //mΪƻ������nΪ������
{
	if (n > m)
		return f(m, m);
	if (m == 0)
		return 1;//����ƻ����Ϊһ�ַ�������Ϊ֮ǰ��û�п����ӵ���������Ѿ���ÿ�����ӷ���һ��ƻ����
	if (n <= 0)
		return 0;//û�����ӿ��Է�ƻ����û�з�����������
	return f(m, n-1) + f(m-n, n);
}
int main() 
{
	int t, m, n;
	cin >> t;
	while (t--)
		cin >> m >> n;
	cout << f(m, n) << endl;
	return 0;
}