#ifndef AR_H_INCLUDED
#define AR_H_INCLUDED

typedef enum
{
 RANDOM_FILL = 1, /**< Рандомная генерация */
 MANUAL_FILL = 2  /**< Ввод с клавиатуры */
} FillMethod;

/**
 * @brief Пытается выделить память
 * @param n Колво строк
 * @param m Колво столбцов
 * @return Указатель на 1 элемент массива
 */
int** allocate_2d_array(size_t n, size_t m);

/**
 * @brief Заполняет массив случайными числами
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void fill_2d_array_random(int** arr, size_t n, size_t m);

/**
 * @brief Заполняет с клавиатуры массив
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void fill_2d_array_manual(int** arr, size_t n, size_t m);

/**
 * @brief Выводит массив
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void print_2d_array(int** arr, size_t n, size_t m);

/**
 * @brief Заменить минимальный элемент каждого столбца нулем.
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 */
void replace_min_in_columns_with_zero(int** arr, size_t n, size_t m);

/**
 * @brief Вставить после каждой строки, содержащей максимальный по модулю элемент, последнюю строку.
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 * @param m Колво столбцов
 * @return Указатель на новый массив
 */
int** insert_last_row_after_max(int** arr, size_t* n, size_t m);

/**
 * @brief Освобождает 2d массив
 * @param arr Указатель на 1 элемент массива
 * @param n Колво строк
 */
void free_2d_array(int** arr, size_t n);

/**
 * @brief Функция ввода целого числа
 * @param prompt Описание того что нужно ввести
 * @return Целое число
 */
int int_input(const char* prompt);

int** copy_2d_array(int** arr, const size_t n, const size_t m);



#endif // AR_H_INCLUDED

