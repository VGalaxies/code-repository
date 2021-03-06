#include <iostream>
#include <cstring>
#define N 33
using namespace std;
void re(char* a, int i) //01转化
{
    if (a[i] == '0')  
        a[i] = '1';
    else a[i] = '0';
}
void act(char* a, int i, int length) //实现按钮功能
{
    re(a, i);
    if (i > 0)    
        re(a, i - 1);
    if (i < length - 1)     
        re(a, i + 1);
}
int main() 
{
    char ori[N], aim[N], temp[N];
    cin >> ori;
    cin >> aim;
    int len = strlen(ori), num1 = 0, num2 = 0, flag = 0, minans;
    for (int k = 0; k < 2; k++)   //枚举两次 
    {
        memcpy(temp, ori, sizeof(ori));  //每次枚举前拷贝ori
        if (k) 
        {  //表示首位不反转 
            for (int i = 1; i < len; i++) 
            {
                if (temp[i - 1] != aim[i - 1]) 
                {
                    act(temp, i, len);
                    num1++;
                }
            }
            if (temp[len - 1] == aim[len - 1])    
                flag = 1;
        }
        else 
        {  //首位翻转
            act(temp, 0, len);
            num2++;
            for (int i = 1; i < len; i++) {
                if (temp[i - 1] != aim[i - 1]) {
                    act(temp, i, len);
                    num2++;
                }
            }
            if (temp[len - 1] == aim[len - 1])    
                flag = 1;
        }
    }
    if (flag) 
    {
        minans = min(num1, num2);
        printf("%d\n", minans);
    }
    else 
        printf("impossible\n");
    return 0;
}