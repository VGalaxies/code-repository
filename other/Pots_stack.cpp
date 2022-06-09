#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
//回溯父节点可能需要栈
using namespace std;
const int maxn = 10005;
struct node
{
    int a;//当前a,b中水容量情况
    int b;
    int parent;//需要回溯路径,由父节点回溯
    string s;//由字符数组记录本节点的操作
    int time;//记录访问本节点开始时的步数
} link[maxn];
int vis[101][101];//标记数组,节点是否入队
//结点个数足够大
int aa, bb, cc;//aa和bb是函数的变换条件
int pp, qq;
int flag;//标记是否找到目标节点
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
        //每次搜索有六种操作,对应六种入队和坐标变换形式
        for (int i = 1; i <= 6; i++)
        {
            switch (i)
            {
            case 1:
                link[qq].a = aa;//将1桶倒满水
                link[qq].b = link[pp].b;//2桶水不变
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
                dis = bb - link[qq].b;//2桶满了需要的水
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
                    ///cout<<"目标节点找到"<<qq<<"是编号"<<endl;//检验
                    flag = 1;
                    return;
                }
                else
                {
                    qq++;
                    ///cout<<qq<<"增加"<<"横纵坐标为"<<xx<<":"<<yy<<endl;//检验
                    vis[xx][yy] = 1;
                    //节点入队
                }
            }
        }
        pp++;//当前节点出队
        ///cout<<pp<<"节点出队"<<endl;
    }
}
int main()
{
    cin >> aa >> bb >> cc;
    //cc是目标节点判定因素
    memset(vis, 0, sizeof(vis));
    pp = qq = 0;
    flag = 0;
    //完整的入队程序
    link[qq].a = 0;
    link[qq].b = 0;
    link[qq].time = 0;
    link[qq].parent = -1;
    link[qq].s = "start";
    vis[0][0] = 1;
    qq++;
    //入队程序结束
    bfs();
    //下面进行非常重要的一关：路径回溯
    stack<string>finds;//将节点的序号压入栈
    ///cout<<qq<<endl;//检验qq值
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