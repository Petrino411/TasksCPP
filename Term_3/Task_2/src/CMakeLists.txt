add_library(VegetableShopLib
        Vegetable.cpp
        Record.cpp
        Shop.cpp
)

target_include_directories(VegetableShopLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
