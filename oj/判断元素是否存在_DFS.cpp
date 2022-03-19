#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int k, x;
int pd(int k, int x)
{
    if (k > x) 
        return 0;
    else if (k == x) 
        return 1;
    return 
        (pd(2 * k + 1, x) || pd(3 * k + 1, x));
}
int main()
{
    scanf("%d,%d", &k, &x);
    if (pd(k, x) == 1) 
        printf("YES");
    else if (pd(k, x) == 0) 
        printf("NO");
    return 0;
}