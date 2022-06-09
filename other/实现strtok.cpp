#include <iostream>  
using namespace std; 
char* Strtok(char* p,const char* sep)
{
	static char* start; //���β����Ӵ������
	if (p)
		start = p;
	for (; *start && strchr(sep, *start); ++start); //�����ָ�����
	if (*start == 0)
		return NULL; 
	char* q = start;
	for (; *start && !strchr(sep, *start); ++start); //�����Ƿָ�����
	if (*start) {
		*start = 0;
		++start;
	}
	return q;
}
int main()
{
	char str[] = "- This, a sample string, OK.";
	//����Ҫ��str�����ȡ����" ,.-"�⼸���ַ��ָ����ִ�
	char * p = Strtok(str," ,.-");
	while (p != NULL) //ֻҪp��ΪNULL����˵���ҵ���һ���Ӵ�
	{
		cout << p << endl;
		p = Strtok(NULL, " ,.-");
		//�������ã���һ������������NULL
	}
	return 0;
}
