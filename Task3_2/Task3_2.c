#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Элемент последовательности по счету k
 * @param previous_element - предыдущий элемент
 * @param k - порядковый номер
 * @return Элемент последовательности по счету k
 */
double get_element(const double previous_element, const int k);

/**
 * @brief Сумма первых n элементов
 * @param n Количество первых элементов
 * @return Сумма первых n элементов
 */
double get_elements_sum(const int n);

/**
 * @brief Функция ввода целого числа
 * @return Целое число
 */
int int_input(void);

/**
 * @brief Функция ввода вещественного числа
 * @return Вещественное число
 */
double double_input(void);

/**
 * @brief Сумма элементов которые больше e
 * @param e ограничение
 * @return Сумма всех элементов больше e
 */
double get_sum_greater_equal_e(const double e);

/**
 *  @brief  Ввод и проверка вещественного числа на положительность
 * @return  Вещественное число
 */
double get_positive_double(void);

/**
 * @brief Выбор пользователя
 */
typedef enum
{
    TASK_A = 1, /**< Задание 1 */
    TASK_B = 2 /**< Задание 2 */
} UserChoice;

/**
 *@brief Точка входа
 * @return 0 в случае успеха
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    printf("Введите %d или %d\n", TASK_A, TASK_B);
    UserChoice choice = int_input();
    switch (choice)
    {
    case TASK_A:
        {
            puts("Введите n");
            int n = int_input();
            double sum = get_elements_sum(n);
            printf("Сумма первых %d элементов последовательности = %lf", n, sum);
            break;
        }
    case TASK_B:
        {
            puts("Введите e");
            double e = get_positive_double();
            printf("Cуммa всех членов последовательности, не меньших заданного числа %lf = %lf", e,
                   get_sum_greater_equal_e(e));
            break;
        }
    default:
        {
            puts("Неверный ввод");
            return 1;
        }
    }
    return 0;
}

double get_element(const double previous_element, const int k)
{
    return previous_element * -1 / (4 * pow(k, 2) + 2 * k);
}

double get_elements_sum(const int n)
{
    double current = -1;
    double sum = current;
    for (int i = 1; i < n; i++)
    {
        sum += get_element(current, i);
    }
    return sum;
}

double get_sum_greater_equal_e(const double e)
{
    double current = -1;
    double sum = 0;
    int k = 1;
    while (fabs(current) >= e - DBL_EPSILON)
    {
        sum += current;
        current = get_element(current, k);
        k++;
    }
    return sum;
}


int int_input(void)
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        abort();
    }
    return value;
}

double double_input(void)
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        abort();
    }
    return value;
}

double get_positive_double(void)
{
    double value = double_input();
    if (value < 0)
    {
        abort();
    }
    return value;
}
