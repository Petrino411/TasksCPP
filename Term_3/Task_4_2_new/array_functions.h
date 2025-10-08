#ifndef TASK_4_2_NEW_ARRAY_FUNCTIONS_H
#define TASK_4_2_NEW_ARRAY_FUNCTIONS_H

/**
 *@brief Выбор метода заполнения массива
 */
typedef enum
{
 RANDOM_FILL = 1, /**< Рандомная генерация */
 MANUAL_FILL = 2  /**< Ввод с клавиатуры */
} FillMethod;

/**
 * @brief Функция ввода целого числа
 * @param prompt Описание того что нужно ввести
 * @return Целое число
 */
int int_input(const char* prompt);

/**
 * @brief Вывод массива
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 */
void print_array(const int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 */
void fill_array_random(int* arr, const size_t size);

/**
 * @brief Заполняет с клавиатуры массив
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 */
void fill_array_manual(int* arr, const size_t size);

/**
 * @brief Заменить минимальный по модулю элемент массива на 0
* @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 */
void replace_min_positive_with_zero(int* arr, const size_t size);

/**
 * @brief Удалить из массива все элементы, первая и последняя цифра которых четная.
* @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @param new_size Новый размер массива
 * @return Указатель на новый массив
 */
int* remove_even_last(const int* arr, const size_t size, const size_t new_size);

/**
 * @brief  Сформировать массив по правилу
* @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return Указатель на новый массив
 */
int* form_array_based_on_rule(const int* arr, const size_t size);

/**
 * @brief Пытается выделить память
 * @param size Размер массива
 * @return Указатель на 1 элемент массива
 */
int* try_allocate_memory(const size_t size);

/**
 * @brief Копирует массив
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return Указатель на новый массив
 */
int* copy_array(const int* arr, const size_t size);

/**
 * @brief Функция для нахождения первой цифры числа
 * @param n Целое число
 * @return Первая цифра цисла
 */
int get_first_digit(const int n);

/**
 * @brief Индекс минимального положительного элемента
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return Индекс минимального положительного элемента
 */
size_t find_min_positive_index(const int* arr, const size_t size);

/**
 * @brief Первый индекс положительного элемента
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return Первый индекс положительного элемента
 */
size_t find_first_positive_index(const int* arr, const size_t size);

/**
 * @brief Расчитывает количество элементов кроме тех у которых первая и последняя четная
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return Количество элементов кроме тех у которых первая и последняя четная
 */
size_t count_elements_to_save(const int* arr, const size_t size);

/**
 * @brief Проверка массива на NULL
 * @param arr Указатель на 1 элемент массива
 * @return Переданный массив, если он не NULL
 */
const int* array_is_not_null(const int* arr);





#endif //TASK_4_2_NEW_ARRAY_FUNCTIONS_H