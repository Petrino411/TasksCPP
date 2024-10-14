#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int int_input();

/**
 * @brief Вывод массива
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void print_array(int* arr, size_t size);

/**
 * @brief Заполняет массив случайными числами
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void fill_array_random(int* arr, size_t size);

/**
 * @brief Заполняет с клавиатуры массив
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void fill_array_manual(int* arr, size_t size);

/**
 * @brief Cумма элементов, значения которых по модулю меньше 10
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 * @return сумма
 */
int sum_of_elements_less_than_10(const int* arr, size_t size);

/**
 * Индексы тех элементов, значения которых больше значения последующего элемента.
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива
 */
void print_indices_greater_than_next(const int* arr, size_t size);

/**
 * @brief Умножить все элементы массива, кратные 3, на третий элемент массива
 * @param arr Указатель на 1 элемент массива
 * @param size размер массива  
 */
void multiply_by_third_element(int* arr, size_t size);


typedef enum
{
    RANDOM_FILL = 1,
    MANUAL_FILL = 2
} FillMethod;


int main()
{
    setlocale(LC_ALL, "Rus");
    int arr[100];


    puts("Введите количество элементов массива (не более 100)");
    int size = int_input();

    printf("Выберите способ заполнения массива:\n");
    printf("%d. Заполнить случайными числами\n", RANDOM_FILL);
    printf("%d. Заполнить с клавиатуры\n", MANUAL_FILL);
    FillMethod fill_method = int_input();

    switch (fill_method)
    {
    case RANDOM_FILL:
        {
            fill_array_random(arr, size);
            break;
        }

    case MANUAL_FILL:
        {
            fill_array_manual(arr, size);
            break;
        }
    default:
        {
            printf("Неверный выбор!\n");
            return 1;
        }
    }

    printf("Исходный массив:\n");
    print_array(arr, size);

    int sum = sum_of_elements_less_than_10(arr, size);
    printf("Сумма элементов, значения которых по модулю меньше 10: %d\n", sum);

    print_indices_greater_than_next(arr, size);

    multiply_by_third_element(arr, size);
    printf("Массив после умножения элементов, кратных 3, на третий элемент:\n");
    print_array(arr, size);

    return 0;
}

int int_input()
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        abort();
    }
    return value;
}

void print_array(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    putchar('\n');
}

void fill_array_random(int* arr, size_t size)
{
    srand(time(0));
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 81 - 40;
    }
}


void fill_array_manual(int* arr, size_t size)
{
    printf("Введите %llu целых чисел:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        printf("Элемент %llu: ", i + 1);
        arr[i] = int_input();
    }
}

int sum_of_elements_less_than_10(const int* arr, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(*(arr + i)) < 10)
        {
            sum += *(arr + i);
        }
    }
    return sum;
}


void print_indices_greater_than_next(const int* arr, size_t size)
{
    printf("Индексы элементов, которые больше следующего:\n");
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("%llu ", i);
        }
    }
    printf("\n");
}

void multiply_by_third_element(int* arr, size_t size)
{
    if (size < 3)
    {
        printf(
            "Недостаточно элементов для умножения на третий элемент (массив должен содержать минимум 3 элемента).\n");
        return;
    }

    int third_element = *(arr + 2);
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 3 == 0)
        {
            arr[i] *= third_element;
        }
    }
}
