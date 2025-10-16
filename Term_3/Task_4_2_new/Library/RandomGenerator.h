#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @class RandomGenerator
     * @brief Генератор случайных целых чисел на основе стандартного механизма случайности C++.
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;  ///< Равномерное распределение для генерации чисел.
        std::mt19937 generator;                           ///< Генератор случайных чисел Мерсенна.

    public:
        /**
         * @brief Конструктор, инициализирующий диапазон случайных чисел.
         *
         * Создаёт генератор, который возвращает случайные целые значения в диапазоне [min, max].
         *
         * @param min Минимальное возможное значение (включительно).
         * @param max Максимальное возможное значение (включительно).
         */
        RandomGenerator(const int min, const int max);

        /**
         * @brief Генерирует случайное целое число в заданном диапазоне.
         *
         * @return Случайное число в диапазоне, указанном при создании генератора.
         */
        int generate() override;
    };
}
