# hobo-gis

Qt and C++ application to learn how QGIS works.

## Development Setup (macOS)

1. Xcode Command Line Tools

    ```sh
    xcode-select --install
    ```

2. Build tools & libraries

    ```sh
    brew install cmake ninja qt gdal pipx
    ```

3. clang-format

    ```sh
    pipx ensurepath     # open a new terminal afterwards
    pipx install clang-format==21.1.8
    ```

4. Download QGIS's `.clang-format` (run in the project root)

   ```sh
   curl -fL -o .clang-format https://raw.githubusercontent.com/qgis/QGIS/master/.clang-format
   ```
