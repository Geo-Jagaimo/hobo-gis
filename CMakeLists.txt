cmake_minimum_required(VERSION 3.21)

project(hobo-gis VERSION 1.0.0 LANGUAGES CXX)

# Use C++20 (same as QGIS)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Run Qt's moc/rcc/uic automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(hobo-gis 
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mapcanvas.cpp
    src/mapcanvas.h
    src/rasterlayer.cpp
    src/rasterlayer.h
    src/layerpanel.cpp
    src/layerpanel.h
)

target_link_libraries(hobo-gis
    PRIVATE
        Qt6::Widgets
)

target_compile_features(hobo-gis
    PRIVATE
        cxx_std_20
)

if(MSVC)
    target_compile_options(hobo-gis PRIVATE /W4 /permissive-)
else()
    target_compile_options(hobo-gis PRIVATE -Wall -Wextra -Wpedantic)
endif()

