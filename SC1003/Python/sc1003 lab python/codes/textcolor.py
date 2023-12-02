#from sense_hat import SenseHat
import time

#s = SenseHat()

color_str = ""

def get_color(color):
    ErrorCounter = 0

    while ErrorCounter != 3:
        color_str = input("Enter a value of the " + color + "color for text(0 to 255):")

        if color_str.isdigit() == True:
            color_str = int(color_str)

            if color_str in range(0, 256):
                return (color_str)
            else:
                ErrorCounter += 1
                print("Enter numbers between 0 and 256")
        else:
            ErrorCounter += 1
            print("Enter PROPER inputs")

        if ErrorCounter == 3:
            color_str = 0
            return (color_str)


#r_int = get_color("red ")
#g_int = get_color("green ")
#b_int = get_color("blue ")
#msg_color = (r_int, g_int, b_int)
#print(msg_color)
#s.show_message("I got it!", text_colour=msg_color)
#s.clear()