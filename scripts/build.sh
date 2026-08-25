#!/usr/bin/env bash
set -Eeuo pipefail
rm -rf build
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/mikis13-ps5 info
./build/mikis13-ps5 selftest
echo "✅ BUILD PASS"
