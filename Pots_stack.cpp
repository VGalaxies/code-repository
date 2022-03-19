#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
//���ݸ��ڵ������Ҫջ
using namespace std;
const int maxn = 10005;
struct node
{
    int a;//��ǰa,b��ˮ�������
    int b;
    int parent;//��Ҫ����·��,�ɸ��ڵ����
    string s;//���ַ������¼���ڵ�Ĳ���
    int time;//��¼���ʱ��ڵ㿪ʼʱ�Ĳ���
} link[maxn];
int vis[101][101];//�������,�ڵ��Ƿ����
//�������㹻��
int aa, bb, cc;//aa��bb�Ǻ����ı任����
int pp, qq;
int flag;//����Ƿ��ҵ�Ŀ��ڵ�
bool judge(int x, int y)
{
    if (vis[x][y] == 1 || x<0 || y<0 || x>aa || y>bb)
        return false;
    else
        return true;
}
void bfs()
{
    int dis;
    while (pp < qq)
    {
        //ÿ�����������ֲ���,��Ӧ������Ӻ�����任��ʽ
        for (int i = 1; i <= 6; i++)
        {
            switch (i)
            {
            case 1:
                link[qq].a = aa;//��1Ͱ����ˮ
                link[qq].b = link[pp].b;//2Ͱˮ����
                link[qq].time = link[pp].time + 1;
                link[qq].s = "FILL(1)";
                link[qq].parent = pp;
                break;
            case 2:
                link[qq].a = link[pp].a;
                link[qq].b = bb;
                link[qq].time = link[pp].time + 1;
                link[qq].s = "FILL(2)";
                link[qq].parent = pp;
                break;
            case 3:
                link[qq].a = link[pp].a;
                link[qq].b = link[pp].b;
                dis = bb - link[qq].b;//2Ͱ������Ҫ��ˮ
                if (link[qq].a >= dis)
                {
                    link[qq].b = bb;
                    link[qq].a -= dis;
                }
                else
                {
                    link[qq].b += link[qq].a;
                    link[qq].a = 0;
                }
                link[qq].time = link[pp].time + 1;
                link[qq].s = "POUR(1,2)";
                link[qq].parent = pp;
                break;
            case 4:
                link[qq].a = link[pp].a;
                link[qq].b = link[pp].b;
                dis = aa - link[qq].a;
                if (link[qq].b >= dis)
                {
                    link[qq].a = aa;
                    link[qq].b -= dis;
                }
                else
                {
                    link[qq].a += link[qq].b;
                    link[qq].b = 0;
                }
                link[qq].time = link[pp].time + 1;
                link[qq].s = "POUR(2,1)";
                link[qq].parent = pp;
                break;
            case 5:
                link[qq].a = 0;
                link[qq].b = link[pp].b;
                link[qq].time = link[pp].time + 1;
                link[qq].s = "DROP(1)";
                link[qq].parent = pp;
                break;
            case 6:
                link[qq].a = link[pp].a;
                link[qq].b = 0;
                link[qq].time = link[pp].time + 1;
                link[qq].s = "DROP(2)";
                link[qq].parent = pp;
                break;
            default:
                ;
            }
            int xx = link[qq].a;
            int yy = link[qq].b;
            if (judge(xx, yy))
            {
                if (xx == cc || yy == cc)
                {
                    ///cout<<"Ŀ��ڵ��ҵ�"<<qq<<"�Ǳ��"<<endl;//����
                    flag = 1;
                    return;
                }
                else
                {
                    qq++;
                    ///cout<<qq<<"����"<<"��������Ϊ"<<xx<<":"<<yy<<endl;//����
                    vis[xx][yy] = 1;
                    //�ڵ����
                }
            }
        }
        pp++;//��ǰ�ڵ����
        ///cout<<pp<<"�ڵ����"<<endl;
    }
}
int main()
{
    cin >> aa >> bb >> cc;
    //cc��Ŀ��ڵ��ж�����
    memset(vis, 0, sizeof(vis));
    pp = qq = 0;
    flag = 0;
    //��������ӳ���
    link[qq].a = 0;
    link[qq].b = 0;
    link[qq].time = 0;
    link[qq].parent = -1;
    link[qq].s = "start";
    vis[0][0] = 1;
    qq++;
    //��ӳ������
    bfs();
    //������зǳ���Ҫ��һ�أ�·������
    stack<string>finds;//���ڵ�����ѹ��ջ
    ///cout<<qq<<endl;//����qqֵ
    int p = qq;
    if (flag)
    {
        cout << link[p].time << endl;
        finds.push(link[p].s);
        while (link[p].parent)
        {
            p = link[p].parent;
            finds.push(link[p].s);
        }
        while (!finds.empty())
        {
            string s = finds.top();
            cout << s << endl;
            finds.pop();
        }
    }
    else
        cout << "impossible" << endl;
    return 0;
}