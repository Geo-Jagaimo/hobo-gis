add_executable(hobo-gis main.cpp)
target_link_libraries(hobo-gis PRIVATE Qt6::Widgets GDAL::GDAL)