#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Перечисление выборов пользователя
 * VOLUME - объем
 * SURFACE_AREA - площадь поверхности
 * EXIT - выход
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
double get_volume(const double length, const double width, const double height);

/**
 * @brief Вычисляет площадь поверхности параллелепипеда
 * @param length длина
 * @param width ширина
 * @param height высота
 * @return double - Площадь поверхности параллелепипеда
 */
double get_square(const double length, const double width, const double height);

/**
 * @ Функция ввода вещестенного числа
 * @return double
 */
double double_input(void);

/**
 * Пытается получить выбор пользователя
 * @return UserChoice
 */
int get_user_choice(void);
/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    printf("%d. Объем\n", VOLUME);
    printf("%d. Площадь поверхности\n", SURFACE_AREA);
    printf("%d. Выход\n", EXIT);

    puts("Введите длину");
    double length = double_input();
    puts("Введите ширину");
    double width = double_input();
    puts("Введите высоту");
    double height = double_input();


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
            puts("Неверный ввод. Попробуйте снова.");
            abort();
        }
    }
    return 0;
}

int get_user_choice(void)
{
    UserChoice choice = EXIT;
    printf("Введите %d (Объем) или %d (Площадь поверхности) или %d (Выход):", VOLUME, SURFACE_AREA, EXIT);
    if (scanf_s("%d", &choice) != 1)
    {
        abort();
    }
    return choice;
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

double get_square(const double length, const double width, const double height)
{
    return 2 * (length * width + width * height + length * height);
}

double get_volume(const double length, const double width, const double height)
{
    return length * width * height;
}
