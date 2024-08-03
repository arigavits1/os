#include <stdio.h>

int putchar(int ic)
{
    char c = (char) ic;
    terminal_putchar(c);
    return ic;
}

void print(const char* str, size_t len)
{
    const unsigned char* bytes = (const unsigned char*)str;
    for (size_t i = 0; i < len; i++)
    {
        putchar(bytes[i]);
    }
}

int printf(const char* restrict format, ...)
{
	va_list parameters;
	va_start(parameters, format);
    int written = 0;

    for (size_t i = 0; i < strlen(format); i++)
    {
        if (format[i] != '%' || format[i + 1] == '%')
        {
            if (format[i] == '%') i++;
            putchar(format[i]);
            written++;
            continue;
        }
        i++;
        if (format[i] == 's')
        {
            const char* str = va_arg(parameters, const char*);
            size_t len = strlen(str);
            print(str, len);
            written += len;
        }
        else if (format[i] == 'c')
        {
            int ic = va_arg(parameters, int);
            putchar(ic);
            written++;
        }
        else if (format[i] == 'd')
        {
            int num = va_arg(parameters, int);

            if (num == 0)
            {
                num = '0';
                putchar(num);
                written++;
                continue;
            }

            if (num < 0)
            {
                num = -num;
                putchar('-');
                written++;
            }

            int temp_num = num;
            size_t count = 0;
            while (temp_num > 0)
            {
                temp_num /= 10;
                count++;
            }
            char str[count];
            for (size_t i = 0; i < count; i++)
            {
                str[count - i - 1] = (num % 10) + 48;
                num /= 10;
            }
            
            print(str, count);
            written += count;
        }
        else
        {
            putchar(format[i - 1]);
            written++;
            putchar(format[i]);
            written++;
        }
    }

    va_end(parameters);
    return written;
}