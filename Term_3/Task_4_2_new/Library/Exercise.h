#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @class Exercise
     * @brief Базовый класс для упражнений, использующих матрицу и генератор значений.
     */
    class Exercise
    {
    protected:
        Matrix<int> matrix;  ///< Матрица (вектор), с которой будет работать упражнение.
        Generator& gen;      ///< Ссылка на объект генератора для заполнения матрицы.

    public:
        /**
         * @brief Конструктор, создающий упражнение с заданным размером матрицы и генератором.
         *
         * @param size Размер матрицы (количество элементов).
         * @param g Ссылка на объект генератора, используемого для заполнения матрицы.
         */
        Exercise(size_t size, Generator& g) : matrix(size), gen(g) {}

        /**
         * @brief Виртуальный деструктор по умолчанию.
         *
         * Обеспечивает корректное уничтожение объектов при работе с полиморфизмом.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Возвращает ссылку на матрицу.
         *
         * Позволяет получить доступ к матрице для чтения или изменения данных.
         *
         * @return Ссылка на объект `Matrix<int>`.
         */
        Matrix<int>& getMatrix() { return matrix; }
    };
}
