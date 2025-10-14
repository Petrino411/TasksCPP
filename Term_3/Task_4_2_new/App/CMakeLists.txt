add_executable(app main.cpp)

target_link_libraries(app PRIVATE library)

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/library)
