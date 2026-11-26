#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")"

INPUT_IT="data/music/music.it"
TMP_WAV="/tmp/umg_music_full.wav"
OUTPUT_OGG="music.ogg"

if [[ ! -f "$INPUT_IT" ]]; then
  echo "ERROR: Missing input file: $INPUT_IT" >&2
  exit 1
fi

trap 'rm -f "$TMP_WAV"' EXIT

xmp -o "$TMP_WAV" "$INPUT_IT"

if [[ ! -s "$TMP_WAV" ]]; then
  echo "ERROR: xmp produced an empty WAV file" >&2
  exit 1
fi

ffmpeg -y -loglevel error -stats -i "$TMP_WAV" -c:a libvorbis -q:a 4 "$OUTPUT_OGG"
echo "Wrote $OUTPUT_OGG ($(du -h "$OUTPUT_OGG" | cut -f1))"
EOF
chmod +x music-it.sh
./music-it.sh