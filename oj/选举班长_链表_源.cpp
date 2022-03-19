#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
struct node//定义结点
{
    int data;//数据域 data，存放结点编号
    node* next;//指针域 next，指向下一个结点
};
int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    node* head, * p, * q;
    head = new node, p = head;//初始化
    for (int i = 1; i <= n; ++i)
    {
        node* temp = new node;
        temp->data = i, p->next = temp, p = temp;//串联结点
    }
    head = head->next, p->next = head, q = head;//首尾相连
    //p 表示顺时针被剔除结点的前一个结点，即 p->next 被删除，这样方便串联前后结点
    //q 表示逆时针被剔除借点的前一个结点，即 q->next 被删除,然后 p 变为删除结点的后一个结点，即 p=p->next
    //(我也不知道当时为什么会这么写...凑合着看吧)
    for (int len = n; len > 0; len -= 2)
    {
        for (int i = 0, kmod = (k - 1) % len; i < kmod; ++i)//每一次 p 都是被删除结点的前一个，只需 k-1 次移动
            p = p->next;
        for (int i = 0, mmod = len - m % len - 1; i < mmod; ++i)//逆时针 m+1 次，即顺时针 len-m-1
            q = q->next;
        if (p == q)
            break;
        printf("%d %d ", p->next->data, q->next->data);
        if (len > 2)
        {
            if (p == q->next)
                q->next = p->next->next, p = q, q = q->next;
            else if (q == p->next)
                p->next = q->next->next, q = p->next;//特殊情况是要删除的两个结点相邻，将前一个结点的 next 跳过这两个结点
            else
                p->next = p->next->next, q->next = q->next->next, q = q->next;//将被删除结点前后结点相连，并将 q 指向被删除结点后一个结点
        }
    }
    if (p == q)
        printf("%d\n", p->next->data);
    return 0;
}