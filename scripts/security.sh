#!/usr/bin/env bash
set -Eeuo pipefail
PATTERN='sk-proj-[A-Za-z0-9_-]{20,}|github_pat_[A-Za-z0-9_]{20,}|gh[pousr]_[A-Za-z0-9_]{20,}'
FOUND=0
while IFS= read -r f; do
  [ -f "$f" ] || continue
  if grep -E "$PATTERN" "$f" >/dev/null 2>&1; then
    echo "❌ possible secret: $f"
    FOUND=1
  fi
done < <({ git ls-files; git ls-files --others --exclude-standard; } | sort -u)
[ "$FOUND" -eq 0 ]
echo "✅ SECRET SCAN PASS"
