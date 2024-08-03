#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
void itoa(int num, char* result);

void* memset(void* bufptr, int value, size_t size);