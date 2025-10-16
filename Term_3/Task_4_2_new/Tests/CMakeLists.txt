include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        tests
        MatrixTests.cpp
        GeneratorTests.cpp
)

target_link_libraries(tests
        PRIVATE
        library
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
