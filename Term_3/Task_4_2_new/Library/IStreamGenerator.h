#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @class IStreamGenerator
     * @brief Генератор чисел, считывающий значения из входного потока.
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;  ///< Поток ввода, из которого считываются значения.

    public:
        /**
         * @brief Конструктор генератора, работающего с указанным потоком ввода.
         *
         * Позволяет использовать любой поток, совместимый с `std::istream` — стандартный ввод, файл, строковый поток и т.д.
         *
         * @param in Ссылка на поток ввода. По умолчанию используется `std::cin`.
         */
        IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief Считывает следующее значение из потока ввода.
         *
         * Метод ожидает ввода числа из потока `in`. Если ввод некорректен, может быть выброшено исключение.
         *
         * @return Считанное целое значение.
         * @throws std::runtime_error В случае ошибки чтения из потока.
         */
        int generate() override;
    };
}
