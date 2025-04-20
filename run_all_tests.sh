#!/usr/bin/env bash
set -e

# Clean previous build
rm -rf build

echo "=== Building and testing with shared library ==="
cmake -B build -DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=OFF -DENABLE_TESTS=ON
cmake --build build --config Release
cd build
ctest --output-on-failure
cd ..

echo "=== Building and testing with static library ==="
rm -rf build
cmake -B build -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC_LIBS=ON -DENABLE_TESTS=ON
cmake --build build --config Release
cd build
ctest --output-on-failure
cd ..

echo "All tests completed for both shared and static builds."