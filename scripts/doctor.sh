#!/usr/bin/env bash
set -Eeuo pipefail

FAIL=0

for f in \
  CMakeLists.txt \
  src/main.cpp \
  src/elf.cpp \
  src/memory.cpp \
  src/cpu.cpp \
  src/scheduler.cpp \
  src/syscalls.cpp \
  src/gpu.cpp \
  src/audio.cpp \
  src/input.cpp \
  src/debugger.cpp
do
  if [ -s "$f" ]; then
    echo "✅ $f"
  else
    echo "❌ $f"
    FAIL=1
  fi
done

jq empty config/lab.json || FAIL=1
./scripts/security.sh || FAIL=1

exit "$FAIL"
