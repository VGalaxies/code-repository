/*
1�����2�Ķ��ٴ�����ӽ�������n��
2����ԭ��n������ȥ2���ݣ�������������2���������µ�n����������
3������ݴ���2�����ݽ�������������
4/һ�����뺯������Ϊ0��2��0���ݣ���1��2��1���ݣ���2��2�Ķ����ݣ��������
*/
#include<iostream>
using namespace std;
void Fun(int n)
{
	int power = 1, index = 0;//2^index=power
	while (power <= n)
	{
		power *= 2;
		index++;
	}
	if (n == 1)
		cout << "2(0)";
	else if (n == 2)
		cout << "2";
	else if (n == 3)//3Ӧ��������
		cout << "2+2(0)";
	else if (n == power / 2) //nΪ2���ݴ�,��n>=4,ע�����������ѭ���������һ��
	{
		cout << "2(";
		Fun(index - 1);//����ָ��
		cout << ")";
	}
	else
	{
		cout << "2(";
		Fun(index - 1);//����ָ��
		cout << ")+";//ע�����źͼӺ�λ��
		Fun(n - power / 2);//��ԭ��n������ȥ2���ݣ������ݹ�
	}
}
int main()
{
	int n;
	cin >> n;
	Fun(n);
	return 0;
}