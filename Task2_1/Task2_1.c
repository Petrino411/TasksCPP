#include <locale.h>
#include <stdio.h>

/**
 * @brief Вычисляет объем параллелепипеда
 * @param length длина
 * @param width ширина
 * @param height высота
 * @return double - Объем параллелепипеда
 */
double get_volume(double length, double width, double height);

/**
 * @brief Вычисляет площадь поверхности параллелепипеда
 * @param length длина
 * @param width ширина
 * @param height высота
 * @return double - Площадь поверхности параллелепипеда
 */
double get_square(double length, double width, double height);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    double length = 0, width = 0, height = 0;
    printf("Введите длину, ширину, высоту в одну строку через пробел: ");
    scanf_s("%lf %lf %lf", &length, &width, &height);
    int choice = 0;
    int is_running = 1;
    while (is_running)
    {
        if (choice == 0)
        {
            printf("1. Объем\n");
            printf("2. Площадь поверхности\n");
            printf("3. Выход\n");
        }
        printf("Введите 1 или 2 или 3\n");
        if (scanf_s("%d", &choice))
        {
            if (choice == 1)
            {
                double volume = get_square(length, width, height);
                printf("Объем: %lf\n", volume);
            }
            else if (choice == 2)
            {
                double square = get_square(length, width, height);
                printf("Площаль поверхности %lf\n", square);
            }
            else if (choice == 3)
            {
                printf("Завершение работы");
                is_running = 0;
            }
        }
        else
        {
            printf("Неверный ввод");
        }
    }

    return 0;
}


double get_square(double length, double width, double height)
{
    return 2 * (length * width + width * height + length * height);
}


double get_volume(double length, double width, double height)
{
    return length * width * height;
}
