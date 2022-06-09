#include<iostream>
using namespace std;
void print_subset(int n) {
    for (int i = 0; i < (1 << n); i++) {
        //i：0~2n，每个i的二进制数对应一个子集。
        for (int j = 0; j < n; j++)   //打印一个子集，即打印i的二进制数中所有的1。
            if (i & (1 << j))
                cout << j << " ";
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;           // n：集合中元素的总数量。
    print_subset(n);  // 打印所有的子集。
}
