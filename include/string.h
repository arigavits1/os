#pragma once
#include <stddef.h>

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);

void* memset(void* bufptr, int value, size_t size);