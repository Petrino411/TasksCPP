#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Перечисление для времени суток
 */
typedef enum {
    MORNING,
    AFTERNOON,
    EVENING,
    NIGHT,
    INVALID_TIME
} TimeOfDay;

/**
 * @brief Определяет время суток на основе введенного времени
 * @param input_time Структура tm с заполненными параметрами часы и минуты
 * @return Значение типа TimeOfDay (утро, день, вечер, ночь)
 */
TimeOfDay determine_time_of_day(const struct tm* input_time);

/**
 * @brief Выводит приветствие соответствующее времени суток
 * @param time_of_day Время суток, определённое функцией determine_time_of_day
 */
void hello_function(TimeOfDay time_of_day);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    struct tm time_info = {0};
    int is_running = 1;
    char input[10];

    while (is_running)
    {
        printf("Введите время в формате часы:минуты (или 'q' для выхода): ");
        scanf_s("%s", input, (unsigned)_countof(input));

        if (strcmp(input, "q") == 0)
        {
            is_running = 0;
            puts("Выход из программы...");
            continue;
        }

        if (sscanf_s(input, "%d:%d", &time_info.tm_hour, &time_info.tm_min) != 2)
        {
            puts("Неправильный формат ввода.");
            continue;
        }

        TimeOfDay time_of_day = determine_time_of_day(&time_info);
        hello_function(time_of_day);
    }

    return 0;
}

/**
 * @brief Определяет время суток на основе введённого времени
 * @param input_time Структура tm с заполненными параметрами часы и минуты
 * @return Время суток (утро, день, вечер, ночь)
 */
TimeOfDay determine_time_of_day(const struct tm* input_time)
{
    if (input_time->tm_hour > 23 || input_time->tm_min > 59)
    {
        return INVALID_TIME;
    }
    if (input_time->tm_hour >= 6 && input_time->tm_hour <= 12)
    {
        return MORNING;
    }
    if (input_time->tm_hour > 12 && input_time->tm_hour < 17)
    {
        return AFTERNOON;
    }
    if (input_time->tm_hour >= 17 && input_time->tm_hour < 23)
    {
        return EVENING;
    }
    return NIGHT;
}

/**
 * @brief Выводит приветствие на основе времени суток
 * @param time_of_day Время суток
 */
void hello_function(TimeOfDay time_of_day)
{
    switch (time_of_day)
    {
        case MORNING:
            puts("Доброе утро");
            break;
        case AFTERNOON:
            puts("Добрый день");
            break;
        case EVENING:
            puts("Добрый вечер");
            break;
        case NIGHT:
            puts("Доброй ночи");
            break;
        case INVALID_TIME:
        default:
            puts("Неправильный формат времени.");
            break;
    }
}