# curly - a simple tool to download xkcd comics

## How to build

First create and move into a build directory:
```bash
mkdir build
cd build
```

Install all dependencies via conan:
```bash
conan install ..
```

Finally build the project with cmake:
```bash
cmake ..
cmake --build .
```
