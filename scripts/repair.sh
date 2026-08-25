#!/usr/bin/env bash
set -Eeuo pipefail

MAX=3

for TRY in $(seq 1 "$MAX"); do
  echo
  echo "=== REPAIR $TRY/$MAX ==="

  chmod +x scripts/*.sh
  rm -rf build

  if ./scripts/test.sh; then
    echo "✅ REPAIR PASS"
    exit 0
  fi

  echo "⚠️ rebuild nodig"
  sleep 2
done

echo "❌ REPAIR FAILED"
exit 1
