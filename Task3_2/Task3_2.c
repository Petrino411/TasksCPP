#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double get_element(int k);

double get_elements_sum(int n);

int int_input();

double double_input();

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

double get_element(int k)
{
    int sign = k % 2 == 0 ? -1 : 1;
    return sign / factorial(2 * k - 1);
}

double get_elements_sum(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += get_element(i);
    }
    return sum;
}

double get_sum_greater_equal_e(double e)
{
    double sum = 0.0;
    int k = 1;
    double term = 1.0;

    while (fabs(term) >= e)
    {
        term = get_element(k);  // Текущий член
        sum += term;
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
