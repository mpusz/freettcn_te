#!/usr/bin/env bash
mkdir build-tidy
cd build-tidy
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
#clang-tidy -p build-tidy -config= te/<file_name>
