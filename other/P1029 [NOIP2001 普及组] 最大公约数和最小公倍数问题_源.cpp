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
        int count = 0;        //ͳ���������ĸ���
        int currentFactor = 2; //�������������Ե�����
        while (quotient > 1) //����1ʱ��־�ŷֽ����
        {
            if (quotient % currentFactor == 0)
            {
                count++;
                while (quotient % currentFactor == 0)
                    quotient /= currentFactor;//���������ͳ�����
            }
            currentFactor++;
        }
        std::cout << (1 << count);//ʹ��λ����������2�ķ���
    }
    return 0;
}