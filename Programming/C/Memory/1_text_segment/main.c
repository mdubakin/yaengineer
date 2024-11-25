#include <stdio.h>

const char *hello = "Hello, World!"; // Строковый литерал попадет в text

void greet()
{
    printf("%s\n", hello);
}

int add(int a, int b)
{
    return a + b; // Машинный код этой функции будет в text
}

int main()
{
    greet();
    int result = add(5, 3);
    printf("5 + 3 = %d\n", result);
    return 0;
}