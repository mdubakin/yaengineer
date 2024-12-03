// Демонстрация основных проблем при работе со стеком
// gcc -g stack_problems.c -o stack_problems

#include <stdio.h>
#include <string.h>
#include <alloca.h>

void stack_overflow_large_local()
{
    // На большинстве систем размер стека по умолчанию 8MB
    // Попытка создать массив больше этого размера приведет к краху
    char huge_array[8 * 1024 * 1024]; // 10MB массив на стеке
    huge_array[0] = 1;                // Попытка использовать массив

    // Получим:
    // Segmentation fault (core dumped)
}

void infinite_recursion(int x)
{
    char buffer[1024]; // Каждый вызов добавляет 1KB на стек
    printf("Глубина рекурсии: %d\n", x);
    infinite_recursion(x + 1); // Рекурсивный вызов без условия выхода

    // Получим:
    // ...
    // Глубина рекурсии: 7810 (тут значения могут отличаться)
    // Segmentation fault (core dumped)
}

void buffer_overflow()
{
    char small_buffer[5];
    char important_data[] = "Важные данные";

    // Попытка записать строку длиннее, чем размер буфера
    strcpy(small_buffer, "Совсем не важные данные");

    // К этому моменту мы уже повредили important_data
    printf("important_data: %s\n", important_data);

    // Ожидаем:
    // important_data: Важные данные
    // Получаем:
    // important_data: �сем не важные данные
}

char *use_after_free()
{
    char local_array[] = "Привет";
    return local_array; // Возвращаем адрес локальной переменной

    // Получим:
    // Segmentation fault (core dumped)
}

void buffer_overflow_executable()
{
    char buffer[2];
    gets(buffer); // Небезопасная функция, не проверяет границы

    // Получим, если введем больше длины массива:
    // *** stack smashing detected ***: terminated
    // Aborted (core dumped)
}

void frame_pointer_corruption()
{
    int array[1];
    array[3] = 0xdeadbeef; // Запись за пределами массива

    // Может повредить указатель кадра стека
}

int main()
{
    // Раскомментируйте для тестирования

    // 1. Переполнение стека из-за большого размера локальных данных
    // stack_overflow_large_local();

    // 2. Переполнение стека из-за бесконечной рекурсии
    // infinite_recursion(0);

    // 3. Выход за границы буфера на стеке (buffer overflow)
    // buffer_overflow();

    // 4. Использование адреса локальной переменной после выхода из функции
    // char *dangling = use_after_free();
    // printf("%s\n", dangling); // Использование висячего указателя

    // 5. Переполнение буфера с возможностью выполнения кода
    // buffer_overflow_executable();

    // 6. Повреждение указателя кадра стека
    // frame_pointer_corruption();

    return 0;
}