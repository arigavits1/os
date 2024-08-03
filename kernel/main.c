#include <vga.h>
#include <stdio.h>

void kernel_main()
{
    const char* k = "kernel";
    char c = 'k';
    int num = -10123;
    terminal_writestring("Hello, kernel world\n");
    terminal_writestring("More text\n");
    print("Hello World\n", strlen("Hello World\n"));
    printf("Hello %d %s %c world", num, k, c);
}

void kernel_init()
{
    terminal_initialize();
    kernel_main();
}