cmake_minimum_required(VERSION 3.22)
project(hobo-gis VERSION 1.0.0 LANGUAGE CXX)

# 以下は QGIS の　CMakeLists.txt と同じ設定
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
include(GenerateExportHeader)
add_compile_options(-Wall -Wextra)

# エディタがコードを解析できるようにする
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core Gui Widgets Concurrent Test)
find_package(GDAL CONFIG REQUIRED)

add_subdirectory(src/app)
