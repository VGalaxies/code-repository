#include<iostream>
using namespace std;
void print_set(int n, int k) {
    for (int i = 0; i < (1 << n); i++) {
        int num = 0, kk = i;   //num统计i中1的个数；kk用来处理i。
        while (kk) {
            kk = kk & (kk - 1);   //清除kk中最后一个1。
            num++;            //统计1的个数。
        }
        if (num == k) {         //二进制数中的1有k个，符合条件。
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    cout << j << " ";
            cout << endl;
        }
    }
}
int main() {
    int n, k;   // n：集合中元素的总数量。k:个数为k的子集。
    cin >> n >> k;
    print_set(n, k);
}