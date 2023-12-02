#--------------------------------------------------------------------------------------
#a)
#from sense_hat import SenseHat
#import time

#s = SenseHat()

#while True:
#  pitch = s.get_orientation()['pitch']
#  roll = s.get_orientation()['roll']
#  print("pitch{0} roll{1}".format(round(pitch,0), round(roll,0)))
#  time.sleep(0.05)

#--------------------------------------------------------------------------------------
#b)
#from sense_hat import SenseHat
#import time

#s = SenseHat()
#b = (0,0,0)
#w = (255,255,255)

#board = [[b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b] ]

#y=2				# y coordinate of marble
#x=2				# x coordinate of marble
#board[y][x]=w		# a white marble

#board_1D=sum(board,[])        # convert to 1-dimension list
#print(board_1D)               # for code debugging
#s.set_pixels(board_1D)    # display it

#--------------------------------------------------------------------------------------
#c)

#from sense_hat import SenseHat
#import time

#s = SenseHat()
#b = (0,0,0)
#w = (255,255,255)

#board = [[b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b],
#         [b,b,b,b,b,b,b,b] ]

#y=2				# y coordinate of marble
#x=2				# x coordinate of marble
#board[y][x]=w		# a white marble

#board_1D=sum(board,[])        # convert to 1-dimension list
#print(board_1D)               # for code debugging
#s.set_pixels(board_1D)    # display it

# This function checks the pitch value and the x coordinate
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.

#def move_marble(pitch,roll,x,y):
#  new_x = x    #assume no change to start with
#  new_y = y    #assume no change to start with
#  board[y][x] = b
#  if 1 < pitch < 179 and x != 0:
#    new_x -= 1    # move left
#  elif 359 > pitch > 179 and x != 7:
#    new_x += 1    # move right

#  if 1 < roll < 179 and y != 7:
#    new_y += 1    # move up
#  elif 359 > roll > 179 and y != 0:
#    new_y -= 1    # move down

#  return new_x, new_y

#while True:
#  pitch = s.get_orientation()['pitch']
#  roll = s.get_orientation()['roll']
#  x,y = move_marble(pitch,roll,x,y)
#  board[y][x] = w
#  s.set_pixels(sum(board,[]))
#  time.sleep(0.05)

#--------------------------------------------------------------------------------------
#d)

#from sense_hat import SenseHat
#import time

#s = SenseHat()
#b = (0, 0, 0)
#w = (255, 255, 255)
#r = (255, 0, 0)

#board = [[r, r, r, b, b, b, b, r],
#         [r, b, b, b, b, b, b, r],
#         [b, b, b, b, b, r, b, r],
#         [b, r, r, b, r, r, b, r],
#         [b, b, b, b, b, b, b, b],
#         [b, r, b, r, r, b, b, b],
#         [b, b, b, r, b, b, b, r],
#         [r, r, b, b, b, r, r, r]]

#y = 2  # y coordinate of marble
#x = 2  # x coordinate of marble
#board[y][x] = w  # a white marble

#board_1D = sum(board, [])  # convert to 1-dimension list
#print(board_1D)  # for code debugging
#s.set_pixels(board_1D)  # display it


#def check_wall(x, y, new_x, new_y):
#    if board[new_y][new_x] != r:
#        return new_x, new_y
#    elif board[new_y][x] != r:
#        return x, new_y
#    elif board[y][new_x] != r:
#        return new_x, y
#    else:
#        return x, y


# This function checks the pitch value and the x coordinate
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.

#def move_marble(pitch, roll, x, y):
#    new_x = x  # assume no change to start with
#    new_y = y  # assume no change to start with
#    board[y][x] = b
#    if 1 < pitch < 179 and x != 0:
#        new_x -= 1  # move left
#    elif 359 > pitch > 179 and x != 7:
#        new_x += 1  # move right

#    if 1 < roll < 179 and y != 7:
#        new_y += 1  # move up
#    elif 359 > roll > 179 and y != 0:
#        new_y -= 1  # move down

#    new_x, new_y = check_wall(x, y, new_x, new_y)
#    return new_x, new_y


#while True:
#    pitch = s.get_orientation()['pitch']
#    roll = s.get_orientation()['roll']
#    x, y = move_marble(pitch, roll, x, y)
#    board[y][x] = w
#    s.set_pixels(sum(board, []))
#    time.sleep(0.05)

#--------------------------------------------------------------------------------------
#e)

#from sense_hat import SenseHat
#import time

#s = SenseHat()
#b = (0, 0, 0)
#w = (255, 255, 255)
#r = (255, 0, 0)
#g = (0, 255, 0)

#board = [[r, r, r, g, b, b, b, r],
#         [r, b, b, b, b, b, b, r],
#         [b, b, b, b, b, r, b, r],
#         [b, r, r, b, r, r, b, r],
#         [b, b, b, b, b, b, b, b],
#         [b, r, b, r, r, b, b, b],
#         [b, b, b, r, b, b, b, r],
#         [r, r, b, b, b, r, r, r]]

#y = 2  # y coordinate of marble
#x = 2  # x coordinate of marble
#board[y][x] = w  # a white marble

#board_1D = sum(board, [])  # convert to 1-dimension list
#print(board_1D)  # for code debugging
#s.set_pixels(board_1D)  # display it


#def check_wall(x, y, new_x, new_y):
#    if board[new_y][new_x] != r:
#        return new_x, new_y
#    elif board[new_y][x] != r:
#        return x, new_y
#    elif board[y][new_x] != r:
#        return new_x, y
#    else:
#        return x, y


# This function checks the pitch value and the x coordinate
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.

#def move_marble(pitch, roll, x, y):
#    new_x = x  # assume no change to start with
#    new_y = y  # assume no change to start with
#    board[y][x] = b
#    if 1 < pitch < 179 and x != 0:
#        new_x -= 1  # move left
#    elif 359 > pitch > 179 and x != 7:
#        new_x += 1  # move right

#    if 1 < roll < 179 and y != 7:
#        new_y += 1  # move up
#    elif 359 > roll > 179 and y != 0:
#        new_y -= 1  # move down

#    new_x, new_y = check_wall(x, y, new_x, new_y)
#    return new_x, new_y

#game_over = False

#while not game_over:
#    pitch = s.get_orientation()['pitch']
#    roll = s.get_orientation()['roll']
#    x, y = move_marble(pitch, roll, x, y)
#    if board[y][x] == g:
#        game_over = True
#        continue
#    board[y][x] = w
#    s.set_pixels(sum(board, []))
#    time.sleep(0.05)

#if game_over:
#    s.show_message('yay!')

#--------------------------------------------------------------------------------------
#challenge

from sense_hat import SenseHat
import time
import random as ran

s = SenseHat()
b = (0, 0, 0)
w = (255, 255, 255)
r = (255, 0, 0)
g = (0, 255, 0)

board = [[r, r, r, b, b, b, b, r],
         [r, b, b, b, b, b, b, r],
         [g, b, b, b, b, r, b, r],
         [b, r, r, b, r, r, b, r],
         [b, b, b, b, b, b, b, b],
         [b, r, b, r, r, b, b, b],
         [b, b, b, r, b, b, b, r],
         [r, r, b, b, b, r, r, r]]

y = 2  # y coordinate of marble
x = 2  # x coordinate of marble
board[y][x] = w  # a white marble

board_1D = sum(board, [])  # convert to 1-dimension list
print(board_1D)  # for code debugging
s.set_pixels(board_1D)  # display it


def check_wall(x, y, new_x, new_y):
    if board[new_y][new_x] != r:
        return new_x, new_y
    elif board[new_y][x] != r:
        return x, new_y
    elif board[y][new_x] != r:
        return new_x, y
    else:
        return x, y


# This function checks the pitch value and the x coordinate
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.

def move_marble(pitch, roll, x, y):
    new_x = x  # assume no change to start with
    new_y = y  # assume no change to start with
    board[y][x] = b
    if 1 < pitch < 179 and x != 0:
        new_x -= 1  # move left
    elif 359 > pitch > 179 and x != 7:
        new_x += 1  # move right

    if 1 < roll < 179 and y != 7:
        new_y += 1  # move up
    elif 359 > roll > 179 and y != 0:
        new_y -= 1  # move down

    new_x, new_y = check_wall(x, y, new_x, new_y)
    return new_x, new_y


timepassed = 0
game_over = False
totaltime = 0


def changeGreen(gY, gX):
    gX = ran.randint(0, 7)
    gY = ran.randint(0, 7)
    if board[gY][gX] == r or board[gY][gX] == w or board[gY][gX] == g:
        changeGreen(gY, gX)
    elif board[gY][gX] == b:
        board[gY][gX] = g
        s.set_pixels(sum(board, []))


gY = 0
gX = 0

while not game_over:
    while totaltime < 10:
        start = time.time()
        pitch = s.get_orientation()['pitch']
        roll = s.get_orientation()['roll']
        x, y = move_marble(pitch, roll, x, y)
        end = time.time()
        timepassed = (end - start) * 10
        totaltime += timepassed
        print(totaltime)
        if board[y][x] == g:
            totaltime = 0
            changeGreen(gY, gX)
            continue
        board[y][x] = w
        s.set_pixels(sum(board, []))
        time.sleep(0.05)
    else:
        game_over = True
        continue

if game_over:
    s.show_message('you lost!')























