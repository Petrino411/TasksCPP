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

    // // 1. Заменить минимальный элемент каждого столбца нулем.
    int** arr_copy = copy_2d_array(arr, n, m);
    replace_min_in_columns_with_zero(arr_copy, n, m);
    printf("Массив после замены минимальных элементов каждого столбца на 0:\n");
    print_2d_array(arr_copy, n, m);

    free_2d_array(arr_copy, n);

    // 2. Вставить после каждой строки с максимальным элементом последнюю строку.
    int** arr_copy2 = copy_2d_array(arr, n, m);
    
    size_t new_n = n;
    arr_copy2 = insert_last_row_after_max(arr_copy2, &new_n, m);
    printf("Массив после вставки последней строки:\n");
    print_2d_array(arr_copy2, new_n, m);


    free_2d_array(arr_copy2, new_n);
    
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
        int min_val = arr[0][j];
        for (size_t i = 1; i < n; i++)
        {
            if (arr[i][j] < min_val)
            {
                min_val = arr[i][j];
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            if (arr[i][j] == min_val)
            {
                arr[i][j] = 0;
            }
        }
    }
}
int** insert_last_row_after_max(int **arr, size_t *n, const size_t m) {
    int max_val = arr[0][0];
    for (size_t i = 0; i < *n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
            }
        }
    }
    
    const int *last_row = arr[*n - 1];
    
    for (size_t i = 0; i < *n; i++) {
        int has_max = 0;
        for (size_t j = 0; j < m; j++) {
            if (arr[i][j] == max_val) {
                has_max = 1;
                break;
            }
        }
        if (has_max) {
            (*n)++;
            arr = realloc(arr, *n * sizeof(int*));
            if (!arr) {
                puts("Ошибка при выделении памяти.");
                abort();
            }
            
            for (size_t k = *n - 1; k > i + 1; k--) {
                arr[k] = arr[k - 1];
            }
            
            arr[i + 1] = malloc(m * sizeof(int));
            for (size_t j = 0; j < m; j++) {
                arr[i + 1][j] = last_row[j];
            }

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

int** copy_2d_array(int** arr, const size_t n, const size_t m)
{
    int** new_arr = allocate_2d_array(n, m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            new_arr[i][j] = arr[i][j];
        }
    }
    return new_arr;
}
