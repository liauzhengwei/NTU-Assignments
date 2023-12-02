import random
r = random

Gnum  = [str(r.randint(0,9)),str(r.randint(0,9)),str(r.randint(0,9)),str(r.randint(0,9))]
Tnum = "".join(Gnum)
print(Tnum)

A = 0
B = 0

while A != 4:
    A=0
    B=0
    guess = ""
    while guess.isdigit() == False or len(guess) != 4:
        guess = input("Enter a 4 digit number: ")

# count position and number
    for i in range(len(Tnum)):
        if Tnum[i] == guess[i]:
            A += 1
        elif Tnum[i] in guess:
            B += 1

    print(A)
    print(B)

#-----------------------------------------------------------------------------------------

#Tnum  = [r.randint(0,9),r.randint(0,9),r.randint(0,9),r.randint(0,9)]
#print(Tnum)

#b = []

#a = ""
#while a.isdigit() == False or len(a) != 4:
#    a = input("Enter a 4 digit number: ")

#for i in a:
#    b.append(i)

#b[0] = int(b[0])
#b[1] = int(b[1])
#b[2] = int(b[2])
#b[3] = int(b[3])

#A=0
#B=0

#if b[0] == Tnum[0]:
#    A += 1
#elif b[0] == Tnum[1] or b[0] == Tnum[2] or b[0] == Tnum[3]:
#    B += 1

#if b[1] == Tnum[1]:
#    A += 1
#elif b[1] == Tnum[0] or b[1] == Tnum[2] or b[1] == Tnum[3]:
#    B += 1

#if b[2] == Tnum[2]:
#    A += 1
#elif b[2] == Tnum[1] or b[2] == Tnum[0] or b[2] == Tnum[3]:
#    B += 1

#if b[3] == Tnum[3]:
#    A += 1
#elif b[3] ==Tnum[1] or b[3] == Tnum[2] or b[3] == Tnum[0]:
#    B += 1

#print(A)
#print(B)