#include <iostream> 
#include <cstring> 
using namespace std; 
int main()
{
	char* buf;
	cout << "strtok usage demo:" << endl;
	char str[] = "- This, a sample string, OK.";
	//����Ҫ��str�����ȡ����" ,.-"�⼸���ַ��ָ����ִ�
	char *p = strtok_s(str, " ,.-",&buf); //��ע�⣬" ,.-"�еĵ�һ���ַ��ǿո�
	while (p != NULL)
	{ //ֻҪp��ΪNULL����˵���ҵ���һ���Ӵ�
		cout << p << endl;
		p = strtok_s(NULL, " ,.-",&buf); //�������ã���һ������������NULL
	}
	return 0;
}