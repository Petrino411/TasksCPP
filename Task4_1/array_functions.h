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
 * @brief Функция ввода натурального числа
 * @param prompt Описание того что нужно ввести
 * @return Натуральное число
 */
int get_positive_int(const char* prompt);

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
 * @brief Cумма элементов, значения которых по модулю меньше 10
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 * @return сумма
 */
int sum_of_elements_less_than_10(const int* arr, const size_t size);

/**
 * Индексы тех элементов, значения которых больше значения последующего элемента.
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива
 */
void print_indices_greater_than_next(const int* arr, const size_t size);

/**
 * @brief Умножить все элементы массива, кратные 3, на третий элемент массива
 * @param arr Указатель на 1 элемент массива
 * @param size Размер массива  
 */
void multiply_by_third_element(const int* arr,const size_t size);

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


#endif // AR_H_INCLUDED

