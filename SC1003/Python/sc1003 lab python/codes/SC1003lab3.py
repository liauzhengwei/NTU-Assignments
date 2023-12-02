from sense_hat import SenseHat
import time

s = SenseHat()

a = ""
b = ""
c = ""

e = ""
f = ""
g = ""

speed = ""

def gettxtRGBvalue(a, b, c):
    ErrorCounter = 0
    while ErrorCounter !=3:
        a = input("Enter a red value for text: ")
        b = input("Enter a green value for text: ")
        c = input("Enter a blue value for text: ")
        if a.isdigit() and b.isdigit() and c.isdigit() == True:
            a = int(a)
            b = int(b)
            c = int(c)
            if a in range(0,256) and b in range(0,256) and c in range(0,256):
                return(a, b, c)
            else:
                ErrorCounter+=1
                print("Enter numbers between 0 and 256")
        else:
            ErrorCounter += 1
            print("Enter PROPER inputs")

        if ErrorCounter == 3:
            print("You exceeded the number of trials")
            quit()

def getbgRGBvalue(e, f, g):
    ErrorCounter = 0
    while ErrorCounter !=3:
        e = input("Enter a red value for bg: ")
        f = input("Enter a green value for bg: ")
        g = input("Enter a blue value for bg: ")
        if e.isdigit() and f.isdigit() and g.isdigit() == True:
            e = int(e)
            f = int(f)
            g = int(g)
            if e in range(0,256) and f in range(0,256) and g in range(0,256):
                return(e, f, g)
            else:
                ErrorCounter+=1
                print("Enter numbers between 0 and 256")
        else:
            ErrorCounter += 1
            print("Enter PROPER inputs")

        if ErrorCounter == 3:
            print("You exceeded the number of trials")
            quit()

def isfloat(num):
  try:
    float(num)
    return True
  except ValueError:
    return False

def getSpeed(speed):
  ErrorCounter = 0
  while ErrorCounter !=3:
    speed = input("Enter a scroll speed value: ")
    if isfloat(speed) == True:
        speed = float(speed)
        p = speed*100
        if p in range(5,101):
          return speed
        else:
          ErrorCounter+=1
          print("Enter a speed btw 0.05 and 1")
    else:
      ErrorCounter += 1
      print("Enter a number")

    if ErrorCounter == 3:
      print("You exceeded the number of trials")
      quit()

s.set_rotation(180)
s.show_message("Hello",text_colour = gettxtRGBvalue(a,b,c), \
                       back_colour = getbgRGBvalue(e,f,g), \
                       scroll_speed = getSpeed(speed))

s.clear()