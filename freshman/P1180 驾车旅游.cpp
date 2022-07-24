#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
double dis, per, fee_first, volume;
double num;
struct Info{
	double gap;
	double fee;
}info[55];
int main() {
	cin >> dis;
	cin >> num >> volume >> per >> fee_first;
	for (int i = 0; i < num; ++i)
		cin >> info[i].gap >> info[i].fee;

}

