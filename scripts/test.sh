#!/usr/bin/env bash
set -Eeuo pipefail

echo
echo "=== BASH ==="

for FILE in scripts/*.sh
do
  bash -n "$FILE"
  echo "✅ $FILE"
done

echo
echo "=== JSON ==="

jq empty config/lab.json
jq empty compatibility/database.json

echo "✅ JSON PASS"

echo
echo "=== SECURITY ==="

./scripts/security.sh

echo
echo "=== BUILD ==="

./scripts/build.sh

echo
echo "=== CTEST ==="

ctest \
  --test-dir build \
  --output-on-failure

echo
echo "✅ TEST SUITE PASS"
