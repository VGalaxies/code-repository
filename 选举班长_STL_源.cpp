#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
int main()
{
    int n, k, m, l, r, t;
    scanf("%d%d%d", &n, &k, &m);
    std::vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);//Ҳ���Դ������õ�ַ���ƣ����ܻ��һЩ
    for (t = n, l = 0, r = n; t;)//l��r �ֱ�����һ��˳����ʱ��ɾ��Ԫ�ص�λ��
    {
        l = (l + k - 1) % t, r = (r + t - m % t) % t, t -= 2;//˳ʱ���� l-1����ʱ���� m ����Ϊɾ���� l �� r ��ָ���һ��Ԫ�أ�
        if (l == r)
            break;
        printf("%d %d ", v[l], v[r]);
        if (t)
            v.erase(v.begin() + l), v.erase(v.begin() + (r -= r > l ? 1 : 0)), l -= l > r ? 1 : 0;
        //ɾ��ʱҪע��˳ʱ��ɾ����Ԫ���±� l ��Сʱ��ʱ��ɾ����Ԫ���±� r Ҫ -1
        //����ʱ��ɾ����Ԫ���±��С����ָ��˳ʱ��ɾ��Ԫ�غ�һ��Ԫ�ص� l ҲҪ -1
    }
    if (l == r)
        printf("%d\n", v[l]);
    return 0;
}