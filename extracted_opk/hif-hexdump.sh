for f in data/gfx/*.hif; do
  {
    echo "=== $f ($(wc -c < "$f") bytes) ==="
    head -c 32 "$f" | hexdump -C
  } >> hif_headers.txt
done