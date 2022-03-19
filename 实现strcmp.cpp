// µœ÷strcmp
#include<iostream>
using namespace std;
int myStrcmp(const char* s1, const char* s2)
{
	
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 > * s2)
			return 1;
		else if (*s1 < *s2)
			return -1;
		else
		{
			s1++;
			s2++;
		}
	}
	s1--;
	s2--;
	if (*s1 != '\0' && *s2 != '\0')
		return 0;
}
int main()
{
	const char* a = "hello";
	const char* b = "hell";
	cout << myStrcmp(a, b);
	return 0;
}