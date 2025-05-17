#ifndef TASK_3_SPEEDLIMIT_H
#define TASK_3_SPEEDLIMIT_H

#include <stdexcept>
#include <sstream>
#include "Сonstraint.h"
#include "Piquet.h"


/**
 * Класс SpeedLimit - ограничение скорости
 */
class SpeedLimit: public Сonstraint  {
private:
    Piquet start; /**@brief Начало ограничения*/
    Piquet end; /**@brief Конец ограничения*/
    double limit; /**@brief Ограничение скорости*/

public:
    /**
     * @brief Конструктор
     */
    SpeedLimit() : limit(0.0) {}

    /**
     * @brief Конструктор с параметрами
     * @param s Начало ограничения
     * @param e Конец ограничения
     * @param l Ограничение скорости
     */
    SpeedLimit(Piquet& s, Piquet& e, double l);

    /**
     * @brief Сериализация в строку
     * @return string
     */
    std::string ToString() const override;

    /**
     * @brief Чтение из потока ввода
     * @param in поток ввода
     */
    void ReadFrom(std::istream& in) override;

    /**
     * @brief Оператор ввода
     * @param out поток
     * @param s объект
     * @return поток
     */
    friend std::ostream& operator<<(std::ostream& out, const SpeedLimit& s);
};


#endif
