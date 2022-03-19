#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct Word
{
	int no;
	char* word;
}word[210];
char ori[20010];
char* buf;
void mysort(void* base, int nelem, unsigned int width, int (*pfCompare)(const void*, const void*))
{

	for (int i = 0; i < nelem; ++i)
	{
		char* pi = (char*)base + i * width;
		for (int j = i + 1; j < nelem; ++j)
		{
			char* pj = (char*)base + j * width;
			if ((pfCompare(pi, pj) > 0))
			{
				for (unsigned int k = 0; k < width; k++)
				{
					int tmp = pi[k];
					pi[k] = pj[k];
					pj[k] = tmp;
				}
			}
		}
	}
}
int MyCompare(const void* a, const void* b)
{
	Word** p1 = (Word**)a;
	Word** p2 = (Word**)b;
	if (strlen((*p1)->word) == strlen((*p2)->word))
		return (*p1)->no < (*p2)->no;
	else
		return strlen((*p1)->word) < strlen((*p2)->word);

}
int main()
{
	cin.getline(ori, 20000);
	int index = 0;
	char* p = strtok_s(ori, ", ", &buf);
	while (p != NULL)
	{
		word[index].word = p;
		word[index].no = index;
		index++;
		p = strtok_s(NULL, ", ", &buf);
	}
	for (int i = 0; i < index; ++i)
		cout << word[i].word << " ";
	cout << endl;
	mysort(word, index, sizeof(Word), MyCompare);
	for (int i = 0; i < index; ++i)
		cout << word[i].word << " ";
}