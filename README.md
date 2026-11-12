# hobo-gis

Qt and C++ application to learn how QGIS works.

## Development Setup (macOS)

### Xcode Command Line Tools

```sh
xcode-select --install
```

### Build tools & libraries

```sh
brew install cmake ninja qt gdal pipx
```

### clang-format

```sh
pipx ensurepath     # open a new terminal afterwards
pipx install clang-format==21.1.8
```
