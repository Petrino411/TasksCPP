#pragma once
#include "Exercise.h"
#include "Matrix.h"
#include "Generator.h"
#include <cstddef>

namespace miit::algebra {
    class Exercise1 : public Exercise {
    private:
        Matrix<int> D;

    public:
        Exercise1(size_t size, Generator &g);

        /**
         * @brief 1. Заменить максимальный по модулю отрицательный элемент массива нулем
         */
        void Task1()  ;

        /**
         * @brief 2. Вставить число K между элементами, которые имеют разные знаки
         * @param K значение, вставляемое между элементами
         */
        void Task2(int K) ;

        /**
         * @brief 3. Из массива D сформировать A по правилу:
         *        Ai = -Di^2, если i < k
         *        Ai = Di-1, если i >= k
         * @param k граница перехода формулы
         */
        void Task3(size_t k) ;
    };
}
