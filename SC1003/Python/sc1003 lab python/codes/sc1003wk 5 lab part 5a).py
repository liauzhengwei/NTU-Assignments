#5a)
from sense_hat import SenseHat
import time
import random

s = SenseHat()

Positions = [(0,0),(0,7),(7,0),(7,7)]

red = (255,0,0)
yellow = (255,255,0)
green = (0,255,0)
blue = (0,0,255)
purple = (102,0,102)

Colors = [red,yellow,green,blue,purple]

a = 4

color = Colors[random.randint(0,a)]
Colors.remove(color)
a-=1
print(color)
s.set_pixel(0,0,color)

color = Colors[random.randint(0,a)]
Colors.remove(color)
a-=1
print(color)
s.set_pixel(7,7,color)

color = Colors[random.randint(0,a)]
Colors.remove(color)
a-=1
print(color)
s.set_pixel(0,7,color)

color = Colors[random.randint(0,a)]
Colors.remove(color)
a-=1
print(color)
s.set_pixel(7,0,color)
