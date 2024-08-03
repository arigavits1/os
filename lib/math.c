#include <math.h>

size_t intlen(int num)
{
    size_t len = 0;
    while (num > 0)
    {
        num /= 10;
        len++;
    }
    return len;
}