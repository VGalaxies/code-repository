#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double m[10010];
int N; 
double sum, K;
double search() 
{
    int temp = 0;
    double l = 0, r = sum / K, mid;
    while (r - l > 1e-10) {
        temp = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < N; ++i)
            temp += (int)(m[i] / mid);
        if (temp >= K)
            l = mid;
        else 
            r = mid;
    }
    return r;
}
int main() {
    double d; 
    while (~scanf("%d%lf", &N, &K)) {
        sum = 0;
        for (int i = 0; i < N; ++i)
            scanf("%lf", &m[i]), sum += m[i];
        d = search();
        printf("%.2f\n", (int)(d * 100) / 100.0);
    }
    return 0;
}