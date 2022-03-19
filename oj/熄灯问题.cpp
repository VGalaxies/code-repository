#include <memory> 
#include <string> 
#include <cstring> 
#include <iostream> 
using namespace std;
int GetBit(char c, int i) //取c的第i位
{
	return	(c >> i) & 1;
}
void SetBit(char& c, int i, int v) //设置c的第i位为v
{
	if( v )
		c |= (1 << i);
	else
		c &= ~(1 << i);
}
void Flip(char& c, int i)//将c的第i位为取反
{
	c ^= (1 << i);
}
void OutputResult(int t, char result[]) //输出结果
{
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 6; ++j) 
		{
			cout << GetBit(result[i], j); 
			if (j < 5)
				cout << " ";
		}
		cout << endl;
	}
}

int main() 
{
	char oriLights[5]; //最初灯矩阵，一个比特表示一盏灯
	char lights[5];	//不停变化的灯矩阵
	char result[5];	//结果开关矩阵
	char switchs;	//某一行的开关状态
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) 
	{
		memset(oriLights, 0, sizeof(oriLights));//状态归零
		for (int i = 0; i < 5; i++) //读入最初灯状态
		{ 
			for(int j = 0; j < 6; j ++ )
			{
				int s;
				cin >> s; 
				SetBit(oriLights[i], j, s);
			}
		}
		for (int n = 0; n < 64; ++n) //遍历首行开关的64种状态，模拟6位二进制
		{ 
			memcpy(lights,oriLights,sizeof(oriLights)); 
			switchs = n; //第i行的开关状态
			for (int i = 0; i < 5; ++i) 
			{
				result[i] = switchs; //第i行的开关方案
				for( int j = 0; j < 6; ++j ) 
				{
					if (GetBit(switchs, j)) 
					{
						if (j > 0)
							Flip(lights[i], j - 1);//改左灯
						Flip(lights[i], j);//改开关位置的灯
						if (j < 5)
							Flip(lights[i], j + 1);//改右灯
					}
				}
				if (i < 4)
					lights[i + 1] ^= switchs;//改下一行的灯
				switchs = lights[i]; //第i+1行开关方案和第i行灯情况同
			}
			if (lights[4] == 0) 
			{
				OutputResult(t, result);
				break;//？？？？会有多解
			}
		} // for( int n = 0; n < 64; n ++ )
	}
return 0;
}
