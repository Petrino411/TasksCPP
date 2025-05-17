#ifndef TASK_3_SPEEDLIMIT_H
#define TASK_3_SPEEDLIMIT_H

#include <stdexcept>
#include <sstream>
#include "Сonstraint.h"
#include "Piquet.h"

class SpeedLimit: public Сonstraint  {
private:
    Piquet start;
    Piquet end;
    double limit;

public:
    /**
     * Конструктор
     */
    SpeedLimit() : limit(0.0) {}

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
