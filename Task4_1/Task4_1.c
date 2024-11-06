#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array_functions.h"

/**
 * @brief  Точка входа
 * @return 0
 */
int main(void)
{
    setlocale(LC_ALL, "Rus");
    const size_t size = get_positive_int("Введите количество элементов массива");
    int* arr = try_allocate_memory(size);

    puts("Выберите способ заполнения массива:");
    printf("%d. Заполнить случайными числами\n", RANDOM_FILL);
    printf("%d. Заполнить с клавиатуры\n", MANUAL_FILL);
    const FillMethod fill_method = int_input(NULL);

    switch (fill_method)
    {
    case RANDOM_FILL:
        {
            fill_array_random(arr, size);
            break;
        }

    case MANUAL_FILL:
        {
            fill_array_manual(arr, size);
            break;
        }
    default:
        {
            puts("Неверный выбор!");
            free(arr);
            return 1;
        }
    }

    printf("Исходный массив:\n");
    print_array(arr, size);

    int sum = sum_of_elements_less_than_10(arr, size);
    printf("Сумма элементов, значения которых по модулю меньше 10: %d\n", sum);

    print_indices_greater_than_next(arr, size);

    int *arr_copy = copy_array(arr, size);
    
    multiply_by_third_element(arr_copy, size);

    puts("Массив после умножения элементов, кратных 3, на третий элемент");
    print_array(arr_copy, size);
    free(arr_copy);

    free(arr);
    return 0;
}

int int_input(const char* prompt)
{
    if (prompt)
    {
        puts(prompt);
    }
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        abort();
    }
    return value;
}

void print_array(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void fill_array_random(int* arr, const size_t size)
{
    const int bottom_limit = int_input("Нижняя граница");
    const int top_limit = int_input("Верхняя граница");
    if (top_limit < bottom_limit)
    {
        puts("Верхняя граница не может быть меньше нижней");
        abort();
    }
    srand(time(0));
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (top_limit - bottom_limit + 1) + bottom_limit;
    }
}


void fill_array_manual(int* arr, const size_t size)
{
    printf("Введите %llu целых чисел:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        printf("Элемент %llu: ", i + 1);
        arr[i] = int_input(NULL);
    }
}

int sum_of_elements_less_than_10(const int* arr, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(arr[i]) < 10)
        {
            sum += arr[i];
        }
    }
    return sum;
}


void print_indices_greater_than_next(const int* arr, const size_t size)
{
    puts("Индексы элементов, которые больше следующего");
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("%llu ", i);
        }
    }
    printf("\n");
}

void multiply_by_third_element(int* arr, const size_t size)
{
    if (size < 3)
    {
        puts("Недостаточно элементов для умножения на третий элемент");
        return;
    }

    const int third_element = arr[2];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 3 == 0)
        {
            arr[i] *= third_element;
        }
    }
    
}

int* try_allocate_memory(const size_t size)
{
    int* array = malloc(size * sizeof(int));
    if (array == NULL)
    {
        abort();
    }
    return array;
}

int* copy_array(const int* arr, const size_t size)
{
    int* arr_copy = try_allocate_memory(size);
    for (size_t i = 0; i < size; i++)
    {
        arr_copy[i] = arr[i];
    }
    return arr_copy;
}

int get_positive_int(const char* prompt)
{
    int value = 0;
    if (prompt)
    {
        value = int_input(prompt);
    }
    if (value < 0)
    {
        abort();
    }
    return value;
}