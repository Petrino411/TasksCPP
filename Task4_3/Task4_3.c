#include "array_functions.h"

int main(void)
{
    setlocale(LC_ALL, "Rus");

    const size_t n = (size_t)int_input("Введите количество строк (n): ");
    const size_t m = (size_t)int_input("Введите количество столбцов (m): ");

    int** arr = allocate_2d_array(n, m);

    puts("Выберите способ заполнения массива:");
    printf("%d. Заполнить случайными числами\n", RANDOM_FILL);
    printf("%d. Заполнить с клавиатуры\n", MANUAL_FILL);
    const FillMethod fill_method = int_input(NULL);

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
    const size_t new_n = get_rows_with_max(arr, n, m);
    int** new_arr = insert_last_row_after_max(arr, n, new_n, m);
    printf("Массив после вставки последней строки:\n");

    print_2d_array(new_arr, new_n, m);
    free_2d_array(new_arr, new_n);
    free_2d_array(arr, n);
    return 0;
}
