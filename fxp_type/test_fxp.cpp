#include <iostream>
#include "fixedpoint.h"

//содержание теста
//1) создать переменную типа fixed_point заданной длины
//2) заполнить каждый байт данных
//3) считать каждый байт данных

int main()
{
    std::cout << "Start program\n";

    //СОЗДАНИЕ ПЕРЕМЕННОЙ
    //создаем переменную
    FixedPoint fp(24, 24, false);
    //считываем общее число байт
    int arr_size = fp.getSizeBytes();
    //выделяем память
    uint8_t *ptr = new uint8_t;
    //смотрим все байты числа
    for (int i = 0; i < arr_size; i++)
    {
        fp.getDataByte(ptr, i);
        std::cout << "byte [" << i << "] = " << unsigned(*ptr) << std::endl;
    }
    //очищаем память
    delete ptr;

    //ЗАПИСЬ БАЙТ В ПЕРЕМЕННУЮ
    //выделяем память под все байты
    ptr = new uint8_t[arr_size];
    //считываем все байты
    fp.getData(ptr);
    //смотрим все байты числа
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << "BEFORE: byte [" << i << "] = " << unsigned(ptr[i]) << std::endl;
        //записываем i в этот байт
        ptr[i] = (uint8_t) i;
        fp.setDataByte(&ptr[i], i);
    }
    //очищаем память
    delete[] ptr;

    //ПРОВЕРКА ЗАПИСИ
    //выделяем память
    ptr = new uint8_t;
    //смотрим все байты числа
    for (int i = 0; i < arr_size; i++)
    {
        fp.getDataByte(ptr, i);
        std::cout << "AFTER: byte [" << i << "] = " << unsigned(*ptr) << std::endl;
    }
    //очищаем память
    delete ptr;


    //ЗАПИСЬ БАЙТОВ В ПЕРЕМЕННУЮ
    //выделяем память под все байты
    ptr = new uint8_t[arr_size];
    //смотрим все байты числа
    for (int i = 0; i < arr_size; i++)
    {
        //записываем i в этот байт
        ptr[i] = (uint8_t) (i + 10);
    }
    fp.setData(ptr);
    //очищаем память
    delete[] ptr;

    //ПРОВЕРКА ЗАПИСИ
    //выделяем память
    ptr = new uint8_t;
    //смотрим все байты числа
    for (int i = 0; i < arr_size; i++)
    {
        fp.getDataByte(ptr, i);
        std::cout << "AFTER: byte [" << i << "] = " << unsigned(*ptr) << std::endl;
    }
    //очищаем память
    delete ptr;



    return 0;
}