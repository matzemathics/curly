# curly - a simple tool to download xkcd comics

## Requirements

- conan (see [download page](https://conan.io/downloads.html))
- [cmake](https://cmake.org/) (usally installed via package manager or visual studio)
- supported toolchains:
  * unix/mac/wsl - both gcc/clang should work
  * windows/visual studio (see [Notes](/.#notes))
  * MinGW might be tricky to set up (I wasn't able to)

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

## Notes

- on windows, you might need to add certificates (open issue)
