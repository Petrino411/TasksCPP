#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array_functions.h"

int main(void)
{
    setlocale(LC_ALL, "Rus");
    
    size_t n = int_input("Введите количество строк (n): ");
    size_t m = int_input("Введите количество столбцов (m): ");

    int** arr = allocate_2d_array(n, m);

    puts("Выберите способ заполнения массива:");
    printf("%d. Заполнить случайными числами\n", RANDOM_FILL);
    printf("%d. Заполнить с клавиатуры\n", MANUAL_FILL);
    FillMethod fill_method = int_input(NULL);

    switch (fill_method)
    {
    case RANDOM_FILL:
        fill_2d_array_random(arr, n, m);
        break;
    case MANUAL_FILL:
        fill_2d_array_manual(arr, n, m);
        break;
    default:
        printf("Неверный выбор!\n");
        free_2d_array(arr, n);
        return 1;
    }

    printf("Исходный массив:\n");
    print_2d_array(arr, n, m);

    // 1. Заменить минимальный элемент каждого столбца нулем.
    replace_min_in_columns_with_zero(arr, n, m);
    printf("Массив после замены минимальных элементов каждого столбца на 0:\n");
    print_2d_array(arr, n, m);

    // 2. Вставить после каждой строки с максимальным элементом последнюю строку.
    arr = insert_last_row_after_max(arr, &n, m);
    printf("Массив после вставки последней строки:\n");
    print_2d_array(arr, n, m);

    // Освобождаем память
    free_2d_array(arr, n);
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

int** allocate_2d_array(const size_t n, const size_t m)
{
    int** arr = malloc(n * sizeof(int*));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(m * sizeof(int));
    }
    return arr;
}

void fill_2d_array_random(int** arr, const size_t n, const size_t m)
{
    const int bottom_limit = int_input("Нижняя граница");
    const int top_limit = int_input("Верхняя граница");
    if (top_limit < bottom_limit)
    {
        puts("Верхняя граница не может быть меньше нижней");
        return;
    }
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arr[i][j] = rand() % (top_limit - bottom_limit + 1) + bottom_limit;
        }
    }
}

void fill_2d_array_manual(int** arr, const size_t n, const size_t m)
{
    printf("Введите элементы массива размером %llu x %llu:\n", n, m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("Элемент [%llu][%llu]: ", i + 1, j + 1);
            arr[i][j] = int_input(NULL);
        }
    }
}

void print_2d_array(int** arr, const size_t n, const size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void replace_min_in_columns_with_zero(int** arr, const size_t n, const size_t m)
{
    for (size_t j = 0; j < m; j++)
    {
        int min_index = 0;
        for (size_t i = 1; i < n; i++)
        {
            if (arr[i][j] < arr[min_index][j])
            {
                min_index = i;
            }
        }
        arr[min_index][j] = 0; // Заменяем минимальный элемент в столбце на 0
    }
}

int** insert_last_row_after_max(int** arr, size_t* n, const size_t m)
{
    int max_element = arr[0][0];
    
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (abs(arr[i][j]) > abs(max_element))
            {
                max_element = arr[i][j];
            }
        }
    }
    
    size_t original_n = *n; 
    for (size_t i = 0; i < original_n; i++)
    {
        int contains_max = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (abs(arr[i][j]) == abs(max_element))
            {
                contains_max = 1;
                break;
            }
        }
        
        if (contains_max)
        {
            
            arr = realloc(arr, (*n + 1) * sizeof(int*));

            
            arr[*n] = (int*)malloc(m * sizeof(int));
            
            for (size_t j = 0; j < m; j++)
            {
                arr[*n][j] = arr[original_n - 1][j];
            }
            
            for (size_t k = *n; k > i + 1; k--)
            {
                arr[k] = arr[k - 1];
            }
            
            arr[i + 1] = (int*)malloc(m * sizeof(int));
            for (size_t j = 0; j < m; j++)
            {
                arr[i + 1][j] = arr[*n][j];
            }

            (*n)++; 
            i++;   
        }
    }

    return arr;
}

void free_2d_array(int** arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
