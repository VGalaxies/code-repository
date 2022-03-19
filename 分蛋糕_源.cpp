#include<iostream>
using namespace std;
#define N 25
#define INF 5005
int f[N][N][N]; 
int w, h, m;
int main() {
    w = h = m = 20;//������ȫ����㣬�����Ҫ�ĸ�����ĸ�
    for (int i = 1; i <= w; i++) 
    {
        for (int j = 1; j <= h; j++) 
        {
            f[i][j][1] = i * j;//��ʼ��
            for (int k = 2; k <= m; k++) 
            {
                f[i][j][k] = INF;//�Ը�����i��j����f[i][j][k]��ʼ������֤�㹻��
                for (int r = 1; r < i; r++) 
                {
                    for (int p = 1; p < k; p++)
                        f[i][j][k] = min(f[i][j][k], max(f[r][j][p], f[i - r][j][k - p]));
                }

                for (int c = 1; c < j; c++) 
                {
                    for (int p = 1; p < k; p++)
                        f[i][j][k] = min(f[i][j][k], max(f[i][c][p], f[i][j - c][k - p]));
                }
            }
        }
    }
    while (cin >> w >> h >> m && (w || h || m)) 
        cout << f[w][h][m] << endl;
    return 0;
}