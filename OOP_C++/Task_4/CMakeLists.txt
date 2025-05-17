cmake_minimum_required(VERSION 3.14)
project(Task_4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/googletest)

file(GLOB SRC_FILES CONFIGURE_DEPENDS Library/*.cpp)

add_library(Lib STATIC ${SRC_FILES})

target_include_directories(Lib PUBLIC ${CMAKE_SOURCE_DIR}/Library)

add_executable(Task_4 App/main.cpp)
target_link_libraries(Task_4
        Lib
        gtest
        gtest_main
        pthread
)

file(GLOB TEST_FILES CONFIGURE_DEPENDS Tests/*.cpp)
add_executable(runTests ${TEST_FILES})
target_link_libraries(runTests
        Lib
        gtest
        gtest_main
        pthread
)

enable_testing()
add_test(NAME AllTests COMMAND runTests)

