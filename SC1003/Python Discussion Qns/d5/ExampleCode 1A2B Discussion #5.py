import random

WIDTH = 4
numList = [1,2,3,4,5,6,7,8,9,0]

############################################################
# functionality: randomly generate the target number
# input:
#   numList: the list with 10 digits
#   count: the number of digits to generate
# output: a list with four digits (integers)

def genNumbers(numList, count):
    random.shuffle(numList)
    numbers = []

    for i in range(count):
        numbers.append(numList[i])

    return numbers
############################################################

############################################################
# functionality: obtain the guessing from users
# input: None
# output: a list with four digits (integers)

def userGuess():

    inputStr = input("Please input 4 digits: ")
    while inputStr.isdigit() == False or len(inputStr) != WIDTH:
        inputStr = input("Wrong format!! Please input 4 digits: ")

    guess = []

    for i in range(WIDTH):
        num = int(inputStr[i])
        guess.append(num)

    return guess
############################################################ 

############################################################
# functionality: compare the user guessing with the target
# input:
#   guessList: the list of four digits (user guessing)
#   answerList: the list of four digits (target)
# output: a tuple (#A, #B)

def checkGuess(guessList, answerList):
    bulls = 0
    cows = 0

    for i in range(len(guessList)):

        for j in range(len(answerList)):

            if guessList[i] == answerList[j]:
                if i == j:
                    bulls += 1
                else:
                    cows += 1

    return (bulls, cows) 
############################################################

############################################################
# Main program putting all function together

answer = genNumbers(numList, WIDTH)
#print(answer)

attemps = 0

while True:
    guesses = userGuess()
    attemps += 1
    #print(guesses)

    result = checkGuess(guesses, answer)
    #print(result)

    if result[0] == WIDTH:
        print("You Win!!")
        print("Attemps: ", attemps)
        break
    else:
        print(result[0], "A (Bulls)", result[1], "B (Cows)")
    
