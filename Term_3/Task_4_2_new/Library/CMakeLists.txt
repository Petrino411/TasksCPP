add_library(library STATIC
        RandomGenerator.cpp
        IStreamGenerator.cpp
        Exercise1.cpp
)

target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
