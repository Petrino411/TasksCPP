#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Перечисление выборов пользователя
 */
typedef enum
{
    VOLUME = 1,
    SURFACE_AREA = 2,
    EXIT = 3
} UserChoice;

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
 * @ Функция ввода целого числа
 * @return int
 */
int int_input();

/**
 * Считывает длину, ширину, высоту в одну строку через пробел
 * @remark При неудаче - abort
 */
void read_dimensions(double* length, double* width, double* height);

/**
 * Пытается считывать выбор пользователя до тех пор, пока не будет введено верное значение
 * @return 
 */
int get_user_choice();
/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    double length = 0, width = 0, height = 0;

    printf("%d. Объем\n", VOLUME);
    printf("%d. Площадь поверхности\n", SURFACE_AREA);
    printf("%d. Выход\n", EXIT);
    
    read_dimensions(&length, &width, &height);

    while (1)
    {
        UserChoice choice = get_user_choice();

        switch (choice)
        {
        case VOLUME:
            {
                double volume = get_volume(length, width, height);
                printf("Объем: %lf\n", volume);
                break;
            }
        case SURFACE_AREA:
            {
                double square = get_square(length, width, height);
                printf("Площадь поверхности: %lf\n", square);
                break;
            }
        case EXIT:
            {
                puts("Завершение работы");
                return 0;
            }
        default:
            {
                puts("Неверный выбор, попробуйте снова.");
                break;
            }
        }
    }
}

int get_user_choice()
{
    UserChoice choice = EXIT;
    while (1)
    {
        puts("Введите 1 (Объем) или 2 (Площадь поверхности) или 3 (Выход):");

        if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > 3)
        {
            puts("Неверный ввод. Попробуйте снова.");
            while (getchar() != '\n'); // Очищаем буфер ввода
            continue;
        }
        return choice;
    }
}


void read_dimensions(double* length, double* width, double* height)
{
    printf("Введите длину, ширину, высоту в одну строку через пробел: ");
    if (!scanf_s("%lf %lf %lf", length, width, height))
    {
        abort();
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
