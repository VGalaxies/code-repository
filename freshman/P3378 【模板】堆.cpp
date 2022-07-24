#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void insert(int x) {
	int index = arr.size();
	arr.push_back(x);
	for (int i = index; i >= 1; i /= 2) {
		if (arr[i / 2] > arr[i])
			swap(arr[i / 2], arr[i]);
		else
			break;
	}
}
void delete_min() {
	int last = arr.back();
	arr.pop_back();
	if (arr.size() == 1)
		return;
	arr[1] = last;
	if (arr.size() == 2)
		return;
	int child = 1;
	for (int i = 1; 2 * i < arr.size(); i = child) {

		if (2 * i + 1 < arr.size()){
			if (arr[2 * i] > arr[2 * i + 1])
				child = 2 * i + 1;
			else
				child = 2 * i;
			if (arr[i] > arr[child])
				swap(arr[child], arr[i]);
		}
		else {
			child = 2 * i;
			if (arr[i] > arr[child])
				swap(arr[child], arr[i]);
		}
		if (child == i)
			break;
	}
}
int n;
int main() {
	cin >> n;
	int op;
	arr.push_back(0);
	for (int i = 0; i < n; ++i) {
		cin >> op;
		switch (op)
		{
		case 1:
			int tmp;
			cin >> tmp;
			insert(tmp);
			break;
		case 2:
			printf("%d\n", arr[1]);
			break;
		case 3:
			delete_min();
		}
	}
}