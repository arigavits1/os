#include <vga.h>
#include <stdio.h>

void kernel_main()
{
    const char* k = "kernel";
    char c = 'k';
    terminal_writestring("Hello, kernel world\n");
    terminal_writestring("More text\n");
    print("Hello World\n", strlen("Hello World\n"));
    printf("Hello %s %c %% \nworld", k, c);
}

void kernel_init()
{
    terminal_initialize();
    kernel_main();
}