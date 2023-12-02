#5a)
#may need to click run to show colors each time
from sense_hat import SenseHat
import time
import random

s = SenseHat()
r = random

Positions = [(0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7),
             (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7),
             (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6), (2, 7),
             (3, 0), (3, 1), (3, 2), (3, 3), (3, 4), (3, 5), (3, 6), (3, 7),
             (4, 0), (4, 1), (4, 2), (4, 3), (4, 4), (4, 5), (4, 6), (4, 7),
             (5, 0), (5, 1), (5, 2), (5, 3), (5, 4), (5, 5), (5, 6), (5, 7),
             (6, 0), (6, 1), (6, 2), (6, 3), (6, 4), (6, 5), (6, 6), (6, 7),
             (7, 0), (7, 1), (7, 2), (7, 3), (7, 4), (7, 5), (7, 6), (7, 7)]

e = 0
f = 0
color = ""
PosSel = []

red = (255, 0, 0)
blue = (0, 0, 255)
green = (0, 255, 0)
yellow = (255, 255, 0)
purple = (102, 0, 102)

Colors = [red, blue, green, yellow, purple]

def getColor(color):
    color = Colors[r.randint(0, len(Colors) - 1)]
    Colors.remove(color)
    return color

def getRow(e):
    e = r.randint(0, 7)
    return e

def getCol(f):
    f = r.randint(0, 7)
    return f

while len(PosSel) != 4:
    Position = (getRow(e), getCol(f))
    if Position in Positions:
        Positions.remove(Position)
        PosSel.append(Position)
    else:
        continue

RowPos1 = PosSel[0][0]
ColPos1 = PosSel[0][1]
RowPos2 = PosSel[1][0]
ColPos2 = PosSel[1][1]
RowPos3 = PosSel[2][0]
ColPos3 = PosSel[2][1]
RowPos4 = PosSel[3][0]
ColPos4 = PosSel[3][1]

s.clear()
s.set_pixel(RowPos1, ColPos1, getColor(color))
s.set_pixel(RowPos2, ColPos2, getColor(color))
s.set_pixel(RowPos3, ColPos3, getColor(color))
s.set_pixel(RowPos4, ColPos4, getColor(color))

#-------------------------------------------------------------------------
#5b)
from sense_hat import SenseHat
import time
import random

s = SenseHat()
ran = random

y = (255, 255, 0)
b = (0, 0, 0)
g = (0, 255, 0)

count = 0
while True:
    if count % 2 == 0:
        North = [b, b, b, b, b, b, b, b,
                 b, b, b, g, b, b, b, b,
                 b, b, g, g, g, b, b, b,
                 b, g, b, g, b, g, b, b,
                 b, b, b, g, b, b, b, b,
                 b, b, b, g, b, b, b, b,
                 b, b, b, b, b, b, b, b,
                 b, b, b, b, b, b, b, b]

        South = [b, b, b, b, b, b, b, b,
                 b, b, b, g, b, b, b, b,
                 b, b, b, g, b, b, b, b,
                 b, g, b, g, b, g, b, b,
                 b, b, g, g, g, b, b, b,
                 b, b, b, g, b, b, b, b,
                 b, b, b, b, b, b, b, b,
                 b, b, b, b, b, b, b, b]

        East = [b, b, b, b, b, b, b, b,
                b, b, b, g, b, b, b, b,
                b, b, b, b, g, b, b, b,
                b, g, g, g, g, g, b, b,
                b, b, b, b, g, b, b, b,
                b, b, b, g, b, b, b, b,
                b, b, b, b, b, b, b, b,
                b, b, b, b, b, b, b, b]

        West = [b, b, b, b, b, b, b, b,
                b, b, b, g, b, b, b, b,
                b, b, g, b, b, b, b, b,
                b, g, g, g, g, g, b, b,
                b, b, g, b, b, b, b, b,
                b, b, b, g, b, b, b, b,
                b, b, b, b, b, b, b, b,
                b, b, b, b, b, b, b, b]

        orientation = [North, South, East, West]

        o = orientation[ran.randint(0, 3)]
        s.set_pixels(o)
        time.sleep(0.25)
        count += 1
        continue
    else:
        N = [b, b, b, b, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, y, y, y, b, b, b,
             b, y, b, y, b, y, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, b]

        S = [b, b, b, b, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, y, b, y, b, y, b, b,
             b, b, y, y, y, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, b]

        E = [b, b, b, b, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, b, y, b, b, b,
             b, y, y, y, y, y, b, b,
             b, b, b, b, y, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, b]

        W = [b, b, b, b, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, y, b, b, b, b, b,
             b, y, y, y, y, y, b, b,
             b, b, y, b, b, b, b, b,
             b, b, b, y, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, b]

        ORIENTATION = [N, S, E, W]
        OR = ORIENTATION[ran.randint(0, 3)]
        s.set_pixels(OR)
        time.sleep(0.25)
        count += 1
        continue
#-------------------------------------------------------------------------
#5c)
from sense_hat import SenseHat
import time
import random

s = SenseHat()
ran = random

y = (255, 255, 0)
b = (0, 0, 0)
g = (0, 255, 0)
p = (102, 0, 102)
r = (255, 0, 0)
blu = (0, 0, 255)
color = [r, g, p, blu, y]

while True:
    c = color[ran.randint(0, 4)]

    North = [b, b, b, b, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, c, c, c, b, b, b,
             b, c, b, c, b, c, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, g]

    South = [b, b, b, b, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, c, b, c, b, c, b, b,
             b, b, c, c, c, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, g]

    East = [b, b, b, b, b, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, b, b, c, b, b, b,
            b, c, c, c, c, c, b, b,
            b, b, b, b, c, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, b, b, b, b, b, b,
            b, b, b, b, b, b, b, g]

    West = [b, b, b, b, b, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, c, b, b, b, b, b,
            b, c, c, c, c, c, b, b,
            b, b, c, b, b, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, b, b, b, b, b, b,
            b, b, b, b, b, b, b, g]

    orientation = [North, South, East, West]

    o = orientation[ran.randint(0, 3)]
    s.set_pixels(o)
    time.sleep(0.25)
    continue
#-------------------------------------------------------------------------
#5d)
from sense_hat import SenseHat
import time
import random

s = SenseHat()
ran = random

ye = (255, 255, 0)
b = (0, 0, 0)
g = (0, 255, 0)
p = (102, 0, 102)
r = (255, 0, 0)
blu = (0, 0, 255)

color = [r, g, p, ye, blu]
starttime = 2
count = 0

while True:
    c = color[1]

    North = [b, b, b, b, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, c, c, c, b, b, b,
             b, c, b, c, b, c, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, g]

    South = [b, b, b, b, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, c, b, b, b, b,
             b, c, b, c, b, c, b, b,
             b, b, c, c, c, b, b, b,
             b, b, b, c, b, b, b, b,
             b, b, b, b, b, b, b, b,
             b, b, b, b, b, b, b, g]

    East = [b, b, b, b, b, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, b, b, c, b, b, b,
            b, c, c, c, c, c, b, b,
            b, b, b, b, c, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, b, b, b, b, b, b,
            b, b, b, b, b, b, b, g]

    West = [b, b, b, b, b, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, c, b, b, b, b, b,
            b, c, c, c, c, c, b, b,
            b, b, c, b, b, b, b, b,
            b, b, b, c, b, b, b, b,
            b, b, b, b, b, b, b, b,
            b, b, b, b, b, b, b, g]

    orientation = [North, South, East, West]
    a = ran.randint(0, 3)

    o = orientation[a]
    s.set_pixels(o)
    time.sleep(starttime)
    acceleration = s.get_accelerometer_raw()
    x = acceleration['x']
    y = acceleration['y']
    coordinates = (round(x), round(y))
    print(coordinates)
    if o == orientation[0] and coordinates == (0, 1):
        print("ok")
        starttime -= 1
        count += 1
        continue
    elif o == orientation[1] and coordinates == (0, -1):
        print("ok")
        starttime -= 1
        count += 1
        continue
    elif o == orientation[2] and coordinates == (-1, 0):
        print("ok")
        starttime -= 1
        count += 1
        continue
    elif o == orientation[3] and coordinates == (1, 0):
        print("ok")
        starttime -= 1
        count += 1
        continue
    else:
        c = color[0]
        North = [b, b, b, b, b, b, b, b,
                 b, b, b, c, b, b, b, b,
                 b, b, c, c, c, b, b, b,
                 b, c, b, c, b, c, b, b,
                 b, b, b, c, b, b, b, b,
                 b, b, b, c, b, b, b, b,
                 b, b, b, b, b, b, b, b,
                 b, b, b, b, b, b, b, g]

        South = [b, b, b, b, b, b, b, b,
                 b, b, b, c, b, b, b, b,
                 b, b, b, c, b, b, b, b,
                 b, c, b, c, b, c, b, b,
                 b, b, c, c, c, b, b, b,
                 b, b, b, c, b, b, b, b,
                 b, b, b, b, b, b, b, b,
                 b, b, b, b, b, b, b, g]

        East = [b, b, b, b, b, b, b, b,
                b, b, b, c, b, b, b, b,
                b, b, b, b, c, b, b, b,
                b, c, c, c, c, c, b, b,
                b, b, b, b, c, b, b, b,
                b, b, b, c, b, b, b, b,
                b, b, b, b, b, b, b, b,
                b, b, b, b, b, b, b, g]

        West = [b, b, b, b, b, b, b, b,
                b, b, b, c, b, b, b, b,
                b, b, c, b, b, b, b, b,
                b, c, c, c, c, c, b, b,
                b, b, c, b, b, b, b, b,
                b, b, b, c, b, b, b, b,
                b, b, b, b, b, b, b, b,
                b, b, b, b, b, b, b, g]

        orientation = [North, South, East, West]

        o = orientation[a]
        s.set_pixels(o)
        print("you lost,successful tries:", count)
        quit()

    continue