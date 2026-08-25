#!/usr/bin/env bash
set -Eeuo pipefail

FAIL=0

echo
echo "=== SOURCES ==="

for FILE in \
  CMakeLists.txt \
  src/main.cpp \
  src/virtual_memory.cpp \
  src/decoder.cpp \
  src/syscall.cpp \
  src/gpu.cpp \
  src/shader.cpp \
  src/input.cpp \
  src/debugger.cpp
do

  if [ -s "$FILE" ]
  then
    echo "✅ $FILE"
  else
    echo "❌ $FILE"
    FAIL=1
  fi

done

echo
echo "=== JSON ==="

jq empty config/lab.json || FAIL=1
jq empty compatibility/database.json || FAIL=1

echo
echo "=== SECURITY ==="

./scripts/security.sh || FAIL=1

exit "$FAIL"
