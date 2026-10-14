#foi baseado no problem set de blur do cs50, porem foi feito em python

from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")

after = before.filter(ImageFilter.BoxBlur(10))

after.save("out.bmp")