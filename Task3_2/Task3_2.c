#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Элемент последовательности по счету k
 * @param k - порядковый номер
 * @return 
 */
double get_element(int k);

/**
 * @brief Сумма первых n элементов
 * @param n Количество первых элементов
 * @return 
 */
double get_elements_sum(int n);

/**
 * @ Функция ввода целого числа
 * @return int
 */
int int_input();

/**
 * @ Функция ввода вещественного числа
 * @return double
 */
double double_input();

/**
 * 
 * @param n 
 * @return 
 */
long double factorial(int n);

double get_sum_greater_equal_e(double e);

/**
 * Выбор пользователя
 */
typedef enum
{
    TASK_A = 1,
    TASK_B = 2
} UserChoice;


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
            double e = double_input();
            printf("Cуммa всех членов последовательности, не меньших заданного числа %lf = %lf", e,
                   get_sum_greater_equal_e(e));
            break;
        }
    default:
        {
            puts("Неверный ввод");
            abort();
        }
    }
    return 0;
}

double get_element(double previous_element, int k)
{
    return previous_element * -1 / (4 * pow(k, 2) + 2 * k);
}

double get_elements_sum(int n)
{
    double current = -1;
    double sum = current;
    for (int i = 1; i <= n; i++)
    {
        sum += get_element(current, i);
        printf("cur_sum = %lf\n", sum);
    }
    return sum;
}

double get_sum_greater_equal_e(double e)
{
    double current = -1;
    double sum = 0;
    int k = 1;
    while (fabs(current) >= e + DBL_EPSILON)
    {
        current = get_element(current, k);
        sum += current;
        k++;
    }
    return sum;
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

double double_input()
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        abort();
    }
    return value;
}

long double factorial(int n)
{
    long double result = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}
