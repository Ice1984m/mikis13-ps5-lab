#!/usr/bin/env bash
set -Eeuo pipefail

rm -rf build

cmake \
  -S . \
  -B build \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=Release

cmake --build build

echo
echo "=== INFO ==="

./build/mikis13-ps5 info

echo
echo "=== SELFTEST ==="

./build/mikis13-ps5 selftest

echo
echo "✅ BUILD PASS"
