#!/usr/bin/env bash
set -Eeuo pipefail

MAX=3

for TRY in $(seq 1 "$MAX")
do

  echo
  echo "========================================"
  echo " PS5 LAB REPAIR $TRY/$MAX"
  echo "========================================"

  chmod +x scripts/*.sh

  mkdir -p \
    reports \
    compatibility \
    build

  if ./scripts/test.sh
  then
    echo
    echo "✅ REPAIR PASS"
    exit 0
  fi

  echo
  echo "⚠️ Test faalde"

  rm -rf build

  sleep 2

done

echo
echo "❌ Repair faalde na $MAX rondes"

exit 1
