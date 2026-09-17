#!/bin/zsh

FROM="$1"
TO="$2"

FILES=("Makefile" "leakCheck")

if [[ ! -d "$FROM" ]]; then
  echo "$FILE is not a directory"
  exit 1
fi

if [[ -e "$TO" ]]; then
  echo "$TO already exists"
  exit 1
fi

mkdir -p "$TO"
for FILE in "${FILES[@]}"; do
  cp "$FROM"/"$FILE" "$TO"/"$FILE"
done
