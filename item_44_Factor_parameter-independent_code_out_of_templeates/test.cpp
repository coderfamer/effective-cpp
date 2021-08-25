#include "square.h"

void test1()
{
    SquareMatrixV1<double, 5> sm1;
    sm1.invert();
    SquareMatrixV1<double, 10> sm2;
    sm2.invert();
}

void test2()
{
    SquareMatrixV2<double, 5> sm1;
    sm1.invert();

    SquareMatrixV2<double, 10> sm2;
    sm2.invert();
}


int main()
{
    test1();
    test2();

    return 0;
}