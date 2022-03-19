#include<iostream>
using namespace std;
void print_subset(int n) {
    for (int i = 0; i < (1 << n); i++) {
        //i��0~2n��ÿ��i�Ķ���������Ӧһ���Ӽ���
        for (int j = 0; j < n; j++)   //��ӡһ���Ӽ�������ӡi�Ķ������������е�1��
            if (i & (1 << j))
                cout << j << " ";
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;           // n��������Ԫ�ص���������
    print_subset(n);  // ��ӡ���е��Ӽ���
}
