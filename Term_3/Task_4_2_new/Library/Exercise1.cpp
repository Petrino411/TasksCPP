#include "Exercise1.h"
#include "Exercise.h"
#include "Matrix.h"
#include "Generator.h"
#include <algorithm>

namespace miit::algebra {

    Exercise1::Exercise1(size_t size, Generator &g)
        : Exercise(size, g), D(size) {
    }

    void Exercise1::Task1()  {
        matrix.fill(gen);

        int maxNegIndex = -1;
        int maxNegAbs = 0;

        for (size_t i = 0; i < matrix.getSize(); ++i) {
            if (matrix[i] < 0 && std::abs(matrix[i]) > maxNegAbs) {
                maxNegAbs = std::abs(matrix[i]);
                maxNegIndex = static_cast<int>(i);
            }
        }

        if (maxNegIndex != -1)
            matrix[maxNegIndex] = 0;
    }

    void Exercise1::Task2(int K) {
        matrix.fill(gen);

        size_t newSize = matrix.getSize() * 2;
        Matrix<int> temp(newSize);
        size_t index = 0;

        for (size_t i = 0; i < matrix.getSize(); ++i) {
            temp[index++] = matrix[i];

            if (i + 1 < matrix.getSize()) {
                if ((matrix[i] < 0 && matrix[i + 1] > 0) ||
                    (matrix[i] > 0 && matrix[i + 1] < 0)) {
                    temp[index++] = K;
                }
            }
        }

        Matrix<int> newMatrix(index);
        for (size_t i = 0; i < index; ++i)
            newMatrix[i] = temp[i];

        matrix = std::move(newMatrix);
    }

    void Exercise1::Task3(size_t k) {
        D.fill(gen);

        if (D.getSize() < matrix.getSize())
        {
            Matrix<int> newD(matrix.getSize());
            for (size_t i = 0; i < D.getSize(); ++i)
                newD[i] = D[i];
            for (size_t i = D.getSize(); i < matrix.getSize(); ++i)
                newD[i] = gen.generate();
            D = std::move(newD);
        }

        for (size_t i = 0; i < matrix.getSize(); ++i)
        {
            if (i < k)
                matrix[i] = -D[i] * D[i];
            else if (i > 0)
                matrix[i] = D[i - 1];
            else
                matrix[i] = D[i];
        }
    }
}
