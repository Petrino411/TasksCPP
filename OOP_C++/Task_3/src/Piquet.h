#ifndef TASK_3_PIQUET_H
#define TASK_3_PIQUET_H


#include <string>

class Piquet {
private:
    int number;
    double shift;
    bool isStandard;

public:
    /**
     * Коструктор
     * @param number - число целое
     * @param shift - дробная часть
     * @param isStandard - целое число или нет
     */
    explicit Piquet(int number = 0, double shift = 0.0, bool isStandard = true);

    /**
     * Сереализация в строку
     * @return string
     */
    std::string ToString() const;

    /**
     * Сдвиг вправо
     * @param meters - метры
     * @return Piquet
     */
    Piquet operator>>(double meters);

    /**
     * Сдвиг влево
     * @param meters - метры
     * @return Piquet
     */
    Piquet operator<<(double meters);

     /**
      * Оператор меньше
      * @param other Другой объект
      * @return bool
      */
    bool operator<(const Piquet& other) const;

    /**
     * Оператор больше
     * @param other Другой объект
     * @return bool
     */
    bool operator>(const Piquet& other);

    /**
     * Оператор сравнения
     * @param other Другой объект
     * @return bool
     */
    bool operator==(const Piquet& other);

    /**
     * Оператор ввода
     * @param in Поток ввода
     * @param p ссылка на объект
     * @return Поток ввода
     */
    friend std::istream& operator>>(std::istream& in, Piquet& p);
    /**
     * Оператор вывода
     * @param out поток вывода
     * @param p объект
     * @return Поток вывода
     */
    friend std::ostream& operator<<(std::ostream& out, const Piquet& p);
};


#endif //TASK_3_PIQUET_H
