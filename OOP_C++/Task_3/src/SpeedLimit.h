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
     * Конструктор
     */
    SpeedLimit() : limit(0.0) {}

    SpeedLimit(Piquet& s, Piquet& e, double l);

    /**
     * Сериализация в строку
     * @return string
     */
    std::string ToString() const override;

    /**
     * Чтение из потока ввода
     * @param in поток ввода
     */
    void ReadFrom(std::istream& in) override;

    /**
     * Оператор ввода
     * @param out поток
     * @param s объект
     * @return поток
     */
    friend std::ostream& operator<<(std::ostream& out, const SpeedLimit& s);
};


#endif
