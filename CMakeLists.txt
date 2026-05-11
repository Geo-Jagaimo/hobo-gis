cmake_minimum_required(VERSION 3.16)

project(hobo-gis VERSION 1.0.0 LANGUAGES CXX)

# Use C++20 (same as QGIS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

# Run Qt's moc/rcc/uic automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(hobo-gis 
    src/main.cpp
)

target_link_libraries(hobo-gis PRIVATE Qt6::Widgets)

# Strict warnings to catch mistakes while learning
target_compile_options(hobo-gis PRIVATE
    -Wall -Wextra -Wpedantic
)
