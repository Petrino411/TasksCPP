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
    puts("1. Объем");
    puts("2. Площадь поверхности");
    puts("3. Выход");

    printf("Введите длину, ширину, высоту в одну строку через пробел: ");
    if (!scanf_s("%lf %lf %lf", &length, &width, &height))
    {
        return 1;
    }
    int choice = 0;
    while (1)
    {
        puts("Введите 1 или 2 или 3");
        if (scanf_s("%d", &choice) != 1)
        {
            puts("Неверный ввод");
            while (getchar() != '\n'); // necessary cringe to clear buffer bcs scanf_s don't do it
            continue;
        }
        switch (choice)
        {
        case 1:
            {
                double volume = get_square(length, width, height);
                printf("Объем: %lf\n", volume);
                break;
            }
        case 2:
            {
                double square = get_square(length, width, height);
                printf("Площаль поверхности %lf\n", square);
                break;
            }
        case 3:
            {
                puts("Завершение работы");
                return 0;
            }
        default: break;
        }
    }
    
}

double get_square(double length, double width, double height)
{
    return 2 * (length * width + width * height + length * height);
}


double get_volume(double length, double width, double height)
{
    return length * width * height;
}
