#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <inttypes.h>
#include <string.h>
#include <math.h>

//размер переменной и число бит под дробную часть являются шаблонами
//класс не определяет операции с числами, а лишь задает способ их хранения в памяти
//хранит сам массив данных и дает доступ к нему
#pragma pack(1)
template <int size, int binary_point, bool issigned>
class FixedPoint
{
public:
    FixedPoint() : len(size), bp(binary_point), s(issigned) { byte_len = (int)ceil(len / 8); data = new uint8_t[byte_len]; }
    ~FixedPoint() { delete[] data; }

    //запрос размера в битах
    int getSize() { return len; }
    //запрос размера в байтах
    int getSizeBytes() { return byte_len; }
    //запрос количества данных после запятой
    int getBinaryPoint() { return bp; }
    //является ли знаковым
    bool isSigned() { return s; }

    //извлечь массив данных
    void getData(uint8_t *arr) { memcpy(arr, data, sizeof(uint8_t) * byte_len); }
    //записать массив данных 
    void setData(uint8_t *arr) { memcpy(data, arr, sizeof(uint8_t) * byte_len); }
    //запросить заданный байт данных
    void getDataByte(uint8_t *ans, int count) { memcpy(ans, data + count, sizeof(uint8_t)); } 
    //задать байт данных
    void setDataByte(uint8_t *arr, int count) { memcpy(data + count, arr, sizeof(uint8_t)); } 

private:
    bool s;
    int len;
    int byte_len;
    int bp;
    uint8_t *data;
};
#pragma pack()

#endif // FIXEDPOINT_H
