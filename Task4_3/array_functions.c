#include "array_functions.h"



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


int** try_allocate_2d_array(const size_t n, const size_t m)
{
    int** arr = allocate_2d_array(n, m);
    if (arr == NULL)
    {
        abort();
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
        abort();
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
        const int min_val = get_column_min(arr[j], n);
        for (size_t i = 0; i < n; i++)
        {
            if (arr[i][j] == min_val)
            {
                arr[i][j] = 0;
            }
        }
    }
}

size_t get_rows_with_max(const int** arr, const size_t n, const size_t m)
{
    const int max_val = get_2d_array_max(arr, n, m);
    size_t rows_with_max = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j] == max_val)
            {
                rows_with_max++;
                break;
            }
        }
    }
    return rows_with_max + n;
}

int** insert_last_row_after_max(int** arr, const size_t old_n, const size_t new_n, const size_t m)
{
    const int max_val = get_2d_array_max(arr, old_n, m);
    
    const int* last_row = arr[old_n - 1];
    int** new_arr = try_allocate_2d_array(new_n, m);

    size_t curr_new_ind = 0;

    for (size_t i = 0; i < old_n; i++)
    {
        for (size_t j = 0; j < m; j++) {
            new_arr[curr_new_ind][j] = arr[i][j];
        }
        curr_new_ind++;
        
        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j] == max_val)
            {
                for (size_t j = 0; j < m; j++) {
                    new_arr[curr_new_ind][j] = last_row[j];
                }
                curr_new_ind++;
                break;
            }
        }
    }
    return new_arr;
}


void free_2d_array(int** arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

int** copy_2d_array(const int** arr, const size_t n, const size_t m)
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

int get_column_min(const int* column, const size_t column_size)
{
    int min_val = column[0];
    for (size_t i = 1; i < column_size; i++)
    {
        if (column[i] < min_val)
        {
            min_val = column[i];
        }
    }
    return min_val;
}

int get_2d_array_max(const int** arr, const size_t n, const size_t m)
{
    int max_val = arr[0][0];
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j] > max_val)
            {
                max_val = arr[i][j];
            }
        }
    }
    return max_val;
}
