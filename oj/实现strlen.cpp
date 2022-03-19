#include<iostream>
using namespace std;
inline unsigned int length(const char* s) {
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
int main(){
	const char* a = "Hello,world";
	cout << length(a);
	return 0;
}

/*
unsigned int Strlen(const char* str){
	const char *eos = str;
    while( *eos++ ) ;
    return( eos - str - 1 );
}
*/
/*
unsigned int strlen(const char* str){
	if ('\0' == *str)
		return 0;
	else
		return strlen(str + 1) + 1;
}
*/