#!/usr/bin/env bash
set -Eeuo pipefail
for f in scripts/*.sh; do bash -n "$f"; done
jq empty config/lab.json
./scripts/security.sh
./scripts/build.sh
ctest --test-dir build --output-on-failure
echo "✅ ALL TESTS PASS"
