#Foi baseado no problem set de edges do cs50, porem foi feito em python

from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")

after = before.filter(ImageFilter.FIND_EDGES)

after.save("out.bmp")