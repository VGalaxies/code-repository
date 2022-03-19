#include<iostream>
using namespace std;
void print_set(int n, int k) {
    for (int i = 0; i < (1 << n); i++) {
        int num = 0, kk = i;   //numͳ��i��1�ĸ�����kk��������i��
        while (kk) {
            kk = kk & (kk - 1);   //���kk�����һ��1��
            num++;            //ͳ��1�ĸ�����
        }
        if (num == k) {         //���������е�1��k��������������
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    cout << j << " ";
            cout << endl;
        }
    }
}
int main() {
    int n, k;   // n��������Ԫ�ص���������k:����Ϊk���Ӽ���
    cin >> n >> k;
    print_set(n, k);
}