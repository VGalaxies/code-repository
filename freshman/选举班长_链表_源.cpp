#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
struct node//������
{
    int data;//������ data����Ž����
    node* next;//ָ���� next��ָ����һ�����
};
int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    node* head, * p, * q;
    head = new node, p = head;//��ʼ��
    for (int i = 1; i <= n; ++i)
    {
        node* temp = new node;
        temp->data = i, p->next = temp, p = temp;//�������
    }
    head = head->next, p->next = head, q = head;//��β����
    //p ��ʾ˳ʱ�뱻�޳�����ǰһ����㣬�� p->next ��ɾ�����������㴮��ǰ����
    //q ��ʾ��ʱ�뱻�޳�����ǰһ����㣬�� q->next ��ɾ��,Ȼ�� p ��Ϊɾ�����ĺ�һ����㣬�� p=p->next
    //(��Ҳ��֪����ʱΪʲô����ôд...�պ��ſ���)
    for (int len = n; len > 0; len -= 2)
    {
        for (int i = 0, kmod = (k - 1) % len; i < kmod; ++i)//ÿһ�� p ���Ǳ�ɾ������ǰһ����ֻ�� k-1 ���ƶ�
            p = p->next;
        for (int i = 0, mmod = len - m % len - 1; i < mmod; ++i)//��ʱ�� m+1 �Σ���˳ʱ�� len-m-1
            q = q->next;
        if (p == q)
            break;
        printf("%d %d ", p->next->data, q->next->data);
        if (len > 2)
        {
            if (p == q->next)
                q->next = p->next->next, p = q, q = q->next;
            else if (q == p->next)
                p->next = q->next->next, q = p->next;//���������Ҫɾ��������������ڣ���ǰһ������ next �������������
            else
                p->next = p->next->next, q->next = q->next->next, q = q->next;//����ɾ�����ǰ�������������� q ָ��ɾ������һ�����
        }
    }
    if (p == q)
        printf("%d\n", p->next->data);
    return 0;
}