#include <iostream>
#include <cstring>
const int max_n = 10;
using namespace std;
bool vis[max_n];//��¼ĳһ�������Ƿ������Ӱڷ�
char mp[max_n][max_n];
int n, k, sum;
void dfs(int x, int y)//����������ע������ĺ���
{
    if (y >= k)//ֻ�аڷ���һ�����ӣ�y�Ż��һ
    { 
        sum++; 
        return;
    }//�����Ӱڷ���ʱ����������һ������
    for (int i = x; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (!vis[j] && mp[i][j] == '#') //����ֻ������������
            {
                vis[j] = true;//���õ�j����������
                dfs(i + 1, y + 1);//������һ�еļ���
                vis[j] = false;//�ݹ���������õ�j��û��������
            }
        }
    }
}
int main()
{
    while (cin >> n >> k && !(n == -1 && k == -1))
    {
        memset(vis, false, sizeof(vis));//��ʼ��
        memset(mp, false, sizeof(mp));
        for (int i = 0; i < n; i++)//�����ά����
            cin >> mp[i];
        sum = 0;
        dfs(0, 0);
        cout << sum << endl;
    }
    return 0;
}