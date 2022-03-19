#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n;
int ans = 0;
int a, b, c, num;
int table[] = { 6,2,5,5,4,5,6,3,7,6 };
int main() {
	cin >> n;
    for (int i = 0; i <= 1111; i++)
        for (int j = 0; j <= 1111; j++){
            a = i; b = j; c = i + j; num = 4;
            while (a / 10 != 0){
                num += table[a % 10];
                a /= 10;
            }
            num += table[a];
            while (b / 10 != 0){
                num += table[b % 10];
                b /= 10;
            }
            num += table[b];
            while (c / 10 != 0){
                num += table[c % 10];
                c /= 10;
            }
            num += table[c];
            if (num == n) 
                ans++;  
        }
    cout << ans;
    return 0;
}