cmake_minimum_required(VERSION 3.10)

# Project Name
project(testing)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link SFML to the project
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
