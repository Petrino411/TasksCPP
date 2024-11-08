#ifndef AR_H_INCLUDED
#define AR_H_INCLUDED


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
void print_array(const int* arr, size_t size);

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
int* remove_even_last(const int* arr, const size_t size, size_t* new_size);

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
int* try_allocate_memory(size_t size);

/**
 * @brief Копирует массив
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return Указатель на новый массив
 */
int* copy_array(const int* arr, size_t size);

/**
 * @brief Функция для нахождения первой цифры числа
 * @param n Целое число
 * @return Первая цифра цисла
 */
int get_first_digit(const int n);


#endif // AR_H_INCLUDED

