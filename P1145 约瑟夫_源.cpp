#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int k, i;
    while (scanf("%d", &k) != EOF)//��������ϰ�ߣ������
    {
        int flag = 1, m = k;
        while (flag)
        {
            m++;//m����Ϊk+1
            int cursor = 0;//���ù����ƶ�
            for (i = 0; i < k; i++)
            {
                cursor = (cursor + m - 1) % (2 * k - i);//��һ�γ���֮�˵ı��
                if (cursor < k)break;//�жϳ��е��Ǹ����Ƿ�С��k��С�ھͽ�����һ��m���ж�
                if (i == k - 1)flag = 0;//˵���Ѿ��ҵ���С��m
            }
        }
        printf("%d\n", m);
    }
    return 0;
}