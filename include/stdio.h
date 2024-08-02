#pragma once

#include <stdarg.h>
#include <string.h>
#include <vga.h>

int putchar(int ic);
bool print(const char* str, size_t len);
int printf(const char* restrict format, ...);