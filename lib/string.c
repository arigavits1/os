#include <string.h>

size_t strlen(const char* str)
{
    size_t len = 0;
    while (str[len]) len++;
    return len;
}

int strcmp(const char* str1, const char* str2)
{
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    size_t max_len = MAX(str1_len, str2_len);

    for (size_t i = 0; i < max_len; i++)
    {
        if (str1[i] != str2[i])
        {
            size_t max_asciiSize = (size_t)(MAX((int)str1, (int)str2));
            if ((int)str1 == (int)max_asciiSize) return 1;
            else return -1;
        }
    }
    return 0;
}

void itoa(int num, char* result)
{
    if (num == 0)
    {
        result[0] = '0';
        return;
    }

    bool negative = false;
    if (num < 0)
    {
        num = -num;
        result[0] = '-';
        result++;
        negative = true;
    }

    size_t count = intlen(num);

    for (size_t i = 0; i < count; i++)
    {
        result[count - i - 1] = (num % 10) + '0';
        num /= 10;
    }

    if (negative)
    {
        result--;
    }            
}

void* memset(void* bufptr, int value, size_t size)
{
    unsigned char* buf = (unsigned char*)bufptr;
    for (size_t i = 0; i < size; i++)
    {
        buf[i] = (unsigned char)value;
    }
    return bufptr;
}