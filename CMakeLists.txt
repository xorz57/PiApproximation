cmake_minimum_required(VERSION 3.24)
project(PiApproximation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(VCPKG_TARGET_TRIPLET MATCHES "-static$")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

find_package(SFML COMPONENTS system window graphics REQUIRED)
find_package(ImGui-SFML REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)
target_link_libraries(${PROJECT_NAME} PUBLIC ImGui-SFML::ImGui-SFML)
