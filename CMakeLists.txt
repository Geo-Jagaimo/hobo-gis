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
find_package(GDAL REQUIRED)

qt_standard_project_setup()

set(APP_ICON ${CMAKE_SOURCE_DIR}/hobogis.icns)
set_source_files_properties(${APP_ICON} PROPERTIES
    MACOSX_PACKAGE_LOCATION "Resources")

add_executable(hobo-gis MACOSX_BUNDLE
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mapcanvas.cpp
    src/mapcanvas.h
    src/rasterlayer.cpp
    src/rasterlayer.h
    src/layerpanel.cpp
    src/layerpanel.h
    ${APP_ICON}
)

set_target_properties(hobo-gis PROPERTIES
    MACOSX_BUNDLE_ICON_FILE "hobogis.icns"
    MACOSX_BUNDLE_BUNDLE_NAME "hobo-gis"
    MACOSX_BUNDLE_BUNDLE_VERSION "1.0.0"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.hobogis"
    MACOSX_BUNDLE_COPYRIGHT "© 2026 Geo-Jagaimo"
)

target_link_libraries(hobo-gis
    PRIVATE
        Qt6::Widgets
        GDAL::GDAL
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
