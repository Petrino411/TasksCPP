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
    size_t size = int_input("Введите количество элементов массива");
    int* arr = try_allocate_memory(size);

    puts("Выберите способ заполнения массива:");
    printf("%d. Заполнить случайными числами\n", RANDOM_FILL);
    printf("%d. Заполнить с клавиатуры\n", MANUAL_FILL);
    FillMethod fill_method = int_input(NULL);

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

    puts("Исходный массив:");
    print_array(arr, size);
    
    int* arr_copy1 = copy_array(arr, size);
    replace_min_positive_with_zero(arr_copy1, size);
    puts("Массив после замены минимального положительного элемента на 0:");
    print_array(arr_copy1, size);
    free(arr_copy1);
    
    int* arr_copy2 = copy_array(arr, size);
    size_t new_size;
    int* filtered_array = remove_even_last(arr_copy2, size, &new_size);
    puts("Массив после удаления элементов с четной первой и последней цифрой:");
    print_array(filtered_array, new_size);
    free(arr_copy2);
    free(filtered_array);
    
    int* arr_copy3 = copy_array(arr, size);
    int* array_A = form_array_based_on_rule(arr_copy3, size);
    printf("Массив A, сформированный по правилам:\n");
    print_array(array_A, size);
    free(arr_copy3);
    free(array_A);

    free(arr);
    return 0;
}

void replace_min_positive_with_zero(int* arr, const size_t size)
{
    int min_positive_index = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && (min_positive_index == -1 || abs(arr[i]) < abs(arr[min_positive_index])))
        {
            min_positive_index = (int)i;
        }
    }

    if (min_positive_index != -1)
    {
        arr[min_positive_index] = 0;
    }
}

int* remove_even_last(const int* arr, const size_t size, size_t* new_size)
{
    int* filtered_arr = try_allocate_memory(size); 
    size_t filtered_size = 0;

    for (size_t i = 0; i < size; i++)
    {
        int first_digit = abs(arr[i]);
        while (first_digit >= 10)
        {
            first_digit /= 10; 
        }

        int last_digit = abs(arr[i]) % 10;  

        if (!(first_digit % 2 == 0 && last_digit % 2 == 0))
        {
            filtered_arr[filtered_size++] = arr[i];  
        }
    }

    *new_size = filtered_size;  
    return realloc(filtered_arr, filtered_size * sizeof(int));  
}

int* form_array_based_on_rule(const int* arr, const size_t size)
{
    int* array_A = try_allocate_memory(size);

    for (size_t i = 0; i < size; i++)
    {
        if (i >= 2 && i <= 11)
        {
            array_A[i] = -(arr[i] * arr[i]); 
        }
        else
        {
            array_A[i] = arr[i] - 1; 
        }
    }

    return array_A;
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

void print_array(int* arr, const size_t size)
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
        return;
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