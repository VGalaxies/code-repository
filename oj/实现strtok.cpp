#include <iostream>  
using namespace std; 
char* Strtok(char* p,const char* sep)
{
	static char* start; //本次查找子串的起点
	if (p)
		start = p;
	for (; *start && strchr(sep, *start); ++start); //跳过分隔符号
	if (*start == 0)
		return NULL; 
	char* q = start;
	for (; *start && !strchr(sep, *start); ++start); //跳过非分隔符号
	if (*start) {
		*start = 0;
		++start;
	}
	return q;
}
int main()
{
	char str[] = "- This, a sample string, OK.";
	//下面要从str逐个抽取出被" ,.-"这几个字符分隔的字串
	char * p = Strtok(str," ,.-");
	while (p != NULL) //只要p不为NULL，就说明找到了一个子串
	{
		cout << p << endl;
		p = Strtok(NULL, " ,.-");
		//后续调用，第一个参数必须是NULL
	}
	return 0;
}
