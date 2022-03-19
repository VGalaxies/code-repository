#include<iostream>
using namespace std;
struct Node
{
	int no;
	Node* next;
};
int main()
{
	int n, m, remain;
	cin >> n >> m;
	Node* first, * last;
	first = last = new Node;
	first->no = 0;
	for (int i = 1; i < n; ++i)
	{
		Node* p = new Node;
		p->no = i;
		last->next = p;
		last = p;
	}
	last->next = first;

	remain = n;
	Node* previous = last;
	while (remain > 1)
	{
		for (int count = 1; count < m; count++)
		{
			previous = previous->next;
		}
		Node* p = previous->next;
		previous->next = p->next;
		delete p;
		remain--;
	}
	cout << previous->no;
	delete previous;
	return 0;
}
