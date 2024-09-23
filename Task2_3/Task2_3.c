#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Выводит приетствие соответствующее полученному из структуры времени
 * @param input_time Структура tm с заполненными параметрами часы и минуты
 */
void hello_function(const struct tm* input_time);

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
            printf("Выход из программы...\n");
            continue;
        }

        if (sscanf_s(input, "%d:%d", &time_info.tm_hour, &time_info.tm_min) != 2)
        {
            printf("Неправильный формат ввода.\n");
            continue;
        }

        hello_function(&time_info);
    }

    return 0;
}

void hello_function(const struct tm* input_time)
{
    if (input_time->tm_hour > 23 || input_time->tm_min > 59)
    {
        printf("Неправильный формат ввода.\n");
        return;
    }
    if (input_time->tm_hour <= 12 && input_time->tm_hour >= 6)
    {
        printf("Доброе утро\n");
        return;
    }
    if (input_time->tm_hour > 12 && input_time->tm_hour < 17)
    {
        printf("Добрый день\n");
        return;
    }
    if (input_time->tm_hour >= 17 && input_time->tm_hour < 23)
    {
        printf("Добрый вечер\n");
        return;
    }
    printf("Доброй ночи\n");
}
