#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Переводит байты в мегабайты
 * @param bytes - количество байт
 * @return double - количество мегабайт
 */
double convert_to_mb(int bytes);

/**
 * @brief Переводит байты в гигабайты
 * @param bytes - количество байт
 * @return double - количество гигабайт
 */
double convert_to_gb(int bytes);

/**
 * @brief Функция ввоода целого числа
 * @return Целое число
 */
int input();

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    puts("Введите байты: ");
    int enter_bytes = input();

    printf("МБ: %lf\n", convert_to_mb(enter_bytes));
    printf("ГБ: %lf\n", convert_to_gb(enter_bytes));

    return 0;
}


int input()
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        abort();
    }
    return value;
}

double convert_to_mb(int bytes)
{
    return bytes / pow(2, 10);
}

double convert_to_gb(int bytes)
{
    return bytes / (pow(2, 10) * pow(2, 10));
}
