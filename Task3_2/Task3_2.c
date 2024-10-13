#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double get_element(int k);

double get_elements_sum(int n);

int int_input();

double double_input();

long long factorial(int n);

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
    UserChoice choice = int_input();
    switch (choice)
    {
    case TASK_A:
        {
            puts("Введите n");
            int n = int_input();
            double sum = get_elements_sum(n);
            printf("Сумма первых %d элементов последовательности = %lf",n,sum);
            break;
        }
    case TASK_B:
        {
            puts("Введите e");
            double e = double_input();
            break;
            
        }
    }
    return 0;
}

double get_element(int k)
{
    return pow(-1, k - 1) / factorial(2 * k - 1);
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

long long factorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
