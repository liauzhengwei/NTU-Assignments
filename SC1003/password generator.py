import random

characters = ["q","w","e","r","t","y","u","i","o","p","a","s","d",
            "f","g","h","j","k","l","z","x","c","v","b","n","m",
            "Q","W","E","R","T","Y","U","I","O","P","A","S","D",
            "F","G","H","J","K","L","Z","X","C","V","B","N","M",
            ",","<",".",">","/","?",";",":","'","{","[","]","}",
            "|","=","+","-","_",")","(","*","&","^","%","$","#",
            "@","!","`","~","1","2","3","4","5","6","7","8","9","0"]

password = ["--"]
wordList = []

while True:
    p = random.randrange(6,33)
    while password.count("--") < p:
        password.append("--")

    while password.count("--") != 0:
        n = random.choice(characters)
        password.append(n)
        password.remove("--")

    a = ' '.join(password)
    print(a)
    if a == wordList:
        continue
    else:
        wordList.append(a)

    password = ["--"]
    print(len(wordList))
    if len(wordList) == 92**32:
        break