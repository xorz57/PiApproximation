cmake_minimum_required(VERSION 3.24)
project(PiApproximation)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)