#include <iostream>
#include "fixedpoint.h"

//содержание теста
//1) создать переменную типа fixed_point заданной длины
//2) заполнить каждый байт данных
//3) считать каждый байт данных

int main()
{
    std::cout << "Start program\n";

    FixedPoint<24, 24, false> fp;

    uint8_t *ptr = new uint8_t[fp.getSize() / 8];



    delete[] ptr;
    return 0;
}