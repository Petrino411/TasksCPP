include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(VegetableShopTests
        tests.cpp
)

target_link_libraries(VegetableShopTests
        PRIVATE
        VegetableShopLib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(VegetableShopTests)
