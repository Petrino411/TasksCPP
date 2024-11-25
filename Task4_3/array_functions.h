#ifndef AR_H_INCLUDED
#define AR_H_INCLUDED
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>



/**
 * @brief Выбор метода зополнения
 */
typedef enum
{
 RANDOM_FILL = 1, /**< Рандомная генерация */
 MANUAL_FILL = 2  /**< Ввод с клавиатуры */
} FillMethod;

/**
 * @brief Выделяет память
 * @param n Колво строк
 * @param m Колво столбцов
 * @return Указатель на 1 элемент массива
 */
int** allocate_2d_array(const size_t n,const size_t m);

/**
 * @brief Пытается выделить память
 * @param n Колво строк
 * @param m Колво столбцов
 * @return Указатель на 1 элемент массива
 */
int** try_allocate_2d_array(const size_t n, const size_t m);

/**
 * @brief Заполняет массив случайными числами
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void fill_2d_array_random(int** arr, const size_t n, const size_t m);

/**
 * @brief Заполняет с клавиатуры массив
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void fill_2d_array_manual(int** arr,const size_t n, const size_t m);

/**
 * @brief Выводит массив
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void print_2d_array(const int** arr, const size_t n, const size_t m);

/**
 * @brief Заменить минимальный элемент каждого столбца нулем.
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void replace_min_in_columns_with_zero(int** arr, const size_t n, const size_t m);

/**
 * @brief Вставить после каждой строки, содержащей максимальный по модулю элемент, последнюю строку.
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 * @return Указатель на новый массив
 */
int** insert_last_row_after_max(int** arr, const size_t old_n, const size_t new_n, const size_t m);

/**
 * @brief Освобождает 2d массив
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 */
void free_2d_array(int** arr, const size_t n);

/**
 * @brief Функция ввода целого числа
 * @param prompt Описание того что нужно ввести
 * @return Целое число
 */
int int_input(const char* prompt);

/**
 * @brief Скопировать двумерный массив
 * @param arr Указатель на 1 элемент
 * @param n Колво строк
 * @param m Колво столбцов
 * @return Указатель на новый массив
 */
int** copy_2d_array(const int** arr, const size_t n, const size_t m);

/**
 * @brief Минимальное значение в колонке column_index
* @param arr Указатель на 1 элемент
 * @param n строки
 * @param column_index индекс колонки
 * @return Минимальный элемент в колонке column_index
 */
int get_column_min(const int** arr, const size_t n, const size_t column_index);

/**
 * @brief Максимум в двумерном массиве
 * @param arr Указатель на 1 элемент
 * @param n Колво строк
 * @param m Колво столбцов 
 * @return Максимальный элемент
 */
int get_2d_array_max(const int** arr, const size_t n, const size_t m);

/**
 * @brief Считает количество строк с максимальным элементом и прибавляет к текущему
 * @param arr Указатель на 1 элемент
 * @param n Колво строк
 * @param m Колво столбцов 
 * @return Новое количество строк
 */
size_t get_rows_with_max(const int** arr, const size_t n, const size_t m);

/**
 * @brief Проверка массива на NULL
 * @param arr Указатель на 1 элемент массива
 * @return Переданный массив, если он не NULL
 */
const int** array_is_not_null(const int** arr);


#endif // AR_H_INCLUDED

