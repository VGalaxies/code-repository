#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int k, i;
    while (scanf("%d", &k) != EOF)//个人输入习惯，请忽略
    {
        int flag = 1, m = k;
        while (flag)
        {
            m++;//m至少为k+1
            int cursor = 0;//设置光标的移动
            for (i = 0; i < k; i++)
            {
                cursor = (cursor + m - 1) % (2 * k - i);//下一次出列之人的编号
                if (cursor < k)break;//判断出列的那个人是否小于k，小于就进行下一个m的判断
                if (i == k - 1)flag = 0;//说明已经找到最小的m
            }
        }
        printf("%d\n", m);
    }
    return 0;
}