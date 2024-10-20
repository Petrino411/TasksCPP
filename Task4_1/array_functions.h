#ifndef ST_H_INCLUDED
#define ST_H_INCLUDED


/**
* @brief Функция ввода целого числа
 * @return Целое число
 */
int int_input(void);

/**
 * @brief Вывод массива
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void print_array(const int* arr, size_t size);

/**
 * @brief Заполняет массив случайными числами
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void fill_array_random(int* arr,const size_t size);

/**
 * @brief Заполняет с клавиатуры массив
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void fill_array_manual(int* arr,const size_t size);

/**
 * @brief Cумма элементов, значения которых по модулю меньше 10
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 * @return сумма
 */
int sum_of_elements_less_than_10(const int* arr,const size_t size);

/**
 * Индексы тех элементов, значения которых больше значения последующего элемента.
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void print_indices_greater_than_next(const int* arr, const size_t size);

/**
 * @brief Умножить все элементы массива, кратные 3, на третий элемент массива
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива  
 */
void multiply_by_third_element(int* arr,const size_t size);

/**
 * @brief Пытается выделить память
 * @param size размер массива
 * @return Указатель на 1 элемент массива
 */
int* try_allocate_memory(size_t size);

/**
 *@brief Выбор метода заполнения массива
 */
typedef enum
{
    RANDOM_FILL = 1, /**< Рандомная генерация */
    MANUAL_FILL = 2  /**< Ввод с клавиатуры */
} FillMethod;





#endif // ST_H_INCLUDED

