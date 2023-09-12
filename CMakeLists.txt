cmake_minimum_required(VERSION 3.24)
project(PiApproximation)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(${PROJECT_NAME} src/Main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

# Define a function to copy the assets directory
function(copy_assets target_directory)
    file(COPY assets DESTINATION ${target_directory})
endfunction()

# Copy assets to both Debug and Release build directories
copy_assets(${CMAKE_BINARY_DIR}/Debug)
copy_assets(${CMAKE_BINARY_DIR}/Release)