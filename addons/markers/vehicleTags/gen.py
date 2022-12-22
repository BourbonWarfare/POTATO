import os
import subprocess
from PIL import Image, ImageDraw, ImageFont, ImageFilter

image_size = 512

# source https://fonts.google.com/specimen/Saira+Stencil+One (Open Font License)
fnt_small = ImageFont.truetype(r"SairaStencilOne-Regular.ttf", 128)
fnt_color = (247, 233, 225, 255)

path_ImageToPAA = r"F:\SteamLibrary\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe"
if (not os.path.isfile(path_ImageToPAA)): raise Exception(f"Missing {path_ImageToPAA}")

draws = [
    ("COY", "COY"), ("1PLT", "1PLT"), ("2PLT", "2PLT"),
    ("ASL", "ALPHA"), ("A1", "A-1"), ("A2", "A-2"),
    ("BSL", "BARVO"), ("B1", "B-1"), ("B2", "B-2"),
    ("CSL", "CHARLY"), ("C1", "C-1"), ("C2", "C-2"),
    ("WSL", "WEAPS"),
    ("ENG", "ENG"),
    ("LOGI", "LOGI"),
    ("IFV1", "IFV-1"), ("IFV2", "IFV-2"), ("IFV3", "IFV-3"), ("IFV4", "IFV-4"),
    ("TH1", "TH-1"), ("TH2", "TH-2"), ("TH3", "TH-3"), ("TH4", "TH-4"),
]

for (name, text) in draws:
    print(f"{name} -> {text}")
    out = Image.new("RGBA", (image_size, image_size), (0, 0, 0, 0))
    draw = ImageDraw.Draw(out)

    x, y, w, h = draw.textbbox((0, 0), text, font=fnt_small)
    if (w > image_size): print(f"Warning text [{text}] width is too large {w} / {image_size}")
    draw.text(((image_size - w) / 2, (image_size - h) / 2), text, font=fnt_small, fill=fnt_color)

    # out.show()

    output_filename_png = f"{name}_ca.png"
    out.save(output_filename_png)
    # print(f"written to {output_filename_png}")

    cmd_convert = [path_ImageToPAA, output_filename_png]
    result = subprocess.run(cmd_convert, capture_output=True)
    if (result.returncode != 0): raise Exception(f"error {result}")
    os.remove(output_filename_png)

print(f"Finished {len(draws)} tags\n")
