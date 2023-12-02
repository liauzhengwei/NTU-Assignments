from sense_hat import SenseHat
import time

s = SenseHat()
a = int(input("Enter a red value for text: "))
b = int(input("Enter a green value for text: "))
c = int(input("Enter a blue value for text: "))

e = int(input("Enter a red value for text: "))
f = int(input("Enter a green value for text: "))
g = int(input("Enter a blue value for text: "))

speed = float(input("Enter a scroll speed number: "))

color_msg = (a,b,c)

color_bg = (e,f,g)

s.set_rotation(180)
s.show_message("Hello",text_colour = color_msg, \
                       back_colour = color_bg, \
                       scroll_speed = speed)
s.clear()
