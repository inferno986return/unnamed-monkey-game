import struct
from pathlib import Path
from PIL import Image


def decode_hif(data: bytes) -> Image.Image:
    if len(data) < 10 or data[0:3] != b"HIF":
        raise ValueError("Not a valid HIF file")

    version = data[3]
    flags = data[4]
    pal_count = data[5] + 1
    width, height = struct.unpack_from("<HH", data, 6)

    unpacked_mode = (flags & 0x80) != 0
    has_alpha = True if version == 1 else ((flags >> 3) & 1) == 1
    entry_size = 4 if has_alpha else 3

    if not unpacked_mode:
        packed_bits = (flags & 0x70) >> 4
        if packed_bits == 0:
            raise ValueError("Invalid packed_bits == 0")
        len_bits = 8 - packed_bits
        len_mask = (1 << len_bits) - 1
        val_mask = (~len_mask) & 0xFF
    else:
        packed_bits = 0
        len_mask = 0
        val_mask = 0

    pos = 10
    palette = []
    for _ in range(pal_count):
        chunk = data[pos : pos + entry_size]
        pos += entry_size
        if has_alpha:
            # Matches (pcVar7[2], pcVar7[1], *pcVar7, pcVar7[3])
            palette.append((chunk[2], chunk[1], chunk[0], chunk[3]))
        else:
            palette.append((chunk[2], chunk[1], chunk[0], 255))

    total_pixels = width * height
    pixels = [(0, 0, 0, 0)] * total_pixels
    out_idx = 0

    def emit(pal_idx: int, count: int) -> None:
        nonlocal out_idx
        rgba = palette[pal_idx % len(palette)]
        end = min(out_idx + count, total_pixels)
        for i in range(out_idx, end):
            pixels[i] = rgba
        out_idx = end

    if version == 2:
        while out_idx < total_pixels and pos < len(data):
            b = data[pos]
            if b != 0xFF:
                if not unpacked_mode:
                    run_len = (b & len_mask) + 1
                    pal_idx = ((b & val_mask) >> len_bits) & 0xFF
                    pos += 1
                else:
                    pal_idx = b
                    run_len = data[pos + 1] + 1
                    pos += 2
                emit(pal_idx, run_len)
            else:
                if pos + 1 >= len(data):
                    break
                sub = struct.unpack_from("<b", data, pos + 1)[0]
                if sub == -1:
                    pal_idx = 0xFF
                    run_len = data[pos + 2] + 1
                    pos += 3
                    emit(pal_idx, run_len)
                elif sub == 1:
                    pal_idx = data[pos + 2]
                    run_len = struct.unpack_from("<H", data, pos + 3)[0] + 1
                    pos += 5
                    emit(pal_idx, run_len)
                elif sub == 2:
                    cur_idx = data[pos + 2]
                    run_len = data[pos + 3] + 1
                    pos += 4
                    for _ in range(run_len):
                        if out_idx >= total_pixels:
                            break
                        emit(cur_idx, 1)
                        cur_idx = (cur_idx + 1) & 0xFF
                elif sub == 0 and unpacked_mode:
                    count = data[pos + 2]
                    raw_len = count + 1
                    for i in range(raw_len):
                        if out_idx >= total_pixels or pos + 3 + i >= len(data):
                            break
                        emit(data[pos + 3 + i], 1)
                    pos += count + 4
                else:
                    raise ValueError(f"Unexpected HIF escape sub={sub} at {pos}")

    img = Image.new("RGBA", (width, height))
    img.putdata(pixels)
    return img


def main() -> None:
    in_dir = Path("data/gfx")
    out_dir = Path("exported_gfx")
    out_dir.mkdir(parents=True, exist_ok=True)
    ok, fail = 0, 0
    for hif_path in sorted(in_dir.glob("*.hif")):
        try:
            img = decode_hif(hif_path.read_bytes())
            img.save(out_dir / f"{hif_path.stem}.png")
            ok += 1
        except Exception as exc:
            print(f"FAIL {hif_path.name}: {exc}")
            fail += 1
    print(f"Exported {ok} PNGs ({fail} failed) to {out_dir}")


if __name__ == "__main__":
    main()