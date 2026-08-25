#!/usr/bin/env bash
set -Eeuo pipefail

echo
echo "=== Bash ==="

for F in scripts/*.sh
do
  bash -n "$F"
  echo "✅ $F"
done

echo
echo "=== JSON ==="

jq empty config/lab.json
jq empty compatibility/database.json

echo "✅ JSON"

echo
echo "=== CMake ==="

test -s CMakeLists.txt
test -s src/main.cpp
test -s src/elf_info.cpp
test -s include/elf_info.hpp

echo "✅ Sources"

echo
echo "=== Build ==="

./scripts/build.sh

echo
echo "=== CTest ==="

ctest \
  --test-dir build \
  --output-on-failure

echo
echo "✅ ALLE TESTS GESLAAGD"
