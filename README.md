# hobo-gis
Qt and C++ application to learn how QGIS works.

## Build

```
mkdir build && cd build
cmake -G Ninja -DCMAKE_PREFIX_PATH=$(brew --prefix qt) ..
ninja
```
