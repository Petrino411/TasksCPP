#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator& gen;

    public:
        Exercise(size_t size, Generator& g) : matrix(size), gen(g) {}
        virtual ~Exercise() = default;

        Matrix<int>& getMatrix() { return matrix; }
    };
}
