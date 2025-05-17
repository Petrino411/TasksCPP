#ifndef TASK_3_PIQUET_H
#define TASK_3_PIQUET_H


#include <string>

/**
 * Класс Piquet - единица измерения расстояния
 */
class Piquet {
private:
    int number; /**@brief Целая часть*/
    double shift; /**@brief Дробная часть*/
    bool isStandard; /** @brief Стандартная единица измерения или нет (100м)*/

public:
    /**
     * @brief Коструктор
     * @param number - число целое
     * @param shift - дробная часть
     * @param isStandard - целое число или нет
     */
    explicit Piquet(int number = 0, double shift = 0.0);

    /**
     * @brief Сереализация в строку
     * @return string
     */
    std::string ToString() const;

    /**
     * @brief Оператор меньше
     * @param other Другой объект
     * @return bool
     */
    bool operator<(const Piquet &other) const;

    /**
     * @brief Оператор больше
     * @param other Другой объект
     * @return bool
     */
    bool operator>(const Piquet &other) const;

    /**
     * @brief Оператор сравнения
     * @param other Другой объект
     * @return bool
     */
    bool operator==(const Piquet &other);

    bool operator!=(const Piquet &other);

    /**
     * @brief Оператор ввода
     * @param in поток ввода
     * @param p объект
     * @return Поток ввода
     */
    friend std::istream &operator>>(std::istream &in, Piquet &p);

    /**
     * @brief Оператор вывода
     * @param out поток вывода
     * @param p объект
     * @return Поток вывода
     */
    friend std::ostream &operator<<(std::ostream &out, const Piquet &p);
};


#endif //TASK_3_PIQUET_H
