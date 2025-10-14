#pragma once
#include <cstddef>


namespace miit::algebra
{
    /**
    * @brief
    */
    class Generator
    {
    public:
        /**
        * @brief
        */
        virtual ~Generator() = default;

        /**
        * @brief
        */
        virtual int generate() = 0;
    };
}
