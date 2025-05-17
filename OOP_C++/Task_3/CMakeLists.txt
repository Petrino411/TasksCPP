cmake_minimum_required(VERSION 3.14)
project(Task_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_subdirectory(external/googletest)

file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_library(core STATIC ${SRC_FILES})

target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(Task_3 src/main.cpp)
target_link_libraries(Task_3 core)

file(GLOB TEST_FILES CONFIGURE_DEPENDS tests/*.cpp)
add_executable(runTests ${TEST_FILES})
target_link_libraries(runTests
        core
        gtest
        gtest_main
        pthread
)

enable_testing()
add_test(NAME AllTests COMMAND runTests)