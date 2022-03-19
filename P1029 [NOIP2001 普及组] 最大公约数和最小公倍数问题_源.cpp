#include <iostream>
int main()
{
    int x, y;
    std::cin >> x >> y;
    if (y % x != 0)
        std::cout << 0;
    else
    {
        int quotient = y / x;
        int count = 0;        //统计素因数的个数
        int currentFactor = 2; //用来试验整除性的因数
        while (quotient > 1) //等于1时标志着分解完毕
        {
            if (quotient % currentFactor == 0)
            {
                count++;
                while (quotient % currentFactor == 0)
                    quotient /= currentFactor;//若能整除就除到底
            }
            currentFactor++;
        }
        std::cout << (1 << count);//使用位运算来产生2的方幂
    }
    return 0;
}