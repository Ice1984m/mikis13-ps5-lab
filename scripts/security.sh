#!/usr/bin/env bash
set -Eeuo pipefail

PATTERN='sk-proj-[A-Za-z0-9_-]{20,}|github_pat_[A-Za-z0-9_]{20,}|gh[pousr]_[A-Za-z0-9_]{20,}'

FOUND=0

while IFS= read -r F
do
  [ -f "$F" ] || continue

  if grep -E "$PATTERN" "$F" >/dev/null 2>&1
  then
    echo "❌ Mogelijke secret: $F"
    FOUND=1
  fi

done < <(
  git ls-files
)

[ "$FOUND" -eq 0 ] ||
  exit 1

echo "✅ Geen herkenbare secrets"
