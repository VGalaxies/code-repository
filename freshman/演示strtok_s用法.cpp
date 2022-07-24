#include <iostream> 
#include <cstring> 
using namespace std; 
int main()
{
	char* buf;
	cout << "strtok usage demo:" << endl;
	char str[] = "- This, a sample string, OK.";
	//下面要从str逐个抽取出被" ,.-"这几个字符分隔的字串
	char *p = strtok_s(str, " ,.-",&buf); //请注意，" ,.-"中的第一个字符是空格
	while (p != NULL)
	{ //只要p不为NULL，就说明找到了一个子串
		cout << p << endl;
		p = strtok_s(NULL, " ,.-",&buf); //后续调用，第一个参数必须是NULL
	}
	return 0;
}