password = input("Enter a password: ")

lowercase_letters = ["q","w","e","r","t","y","u","i","o","p","a","s","d",
            "f","g","h","j","k","l","z","x","c","v","b","n","m"]

uppercase_letters = ["Q","W","E","R","T","Y","U","I","O","P","A","S","D",
            "F","G","H","J","K","L","Z","X","C","V","B","N","M"]

special_characters = [",","<",".",">","/","?",";",":","'","{","[","]","}",
            "|","=","+","-","_",")","(","*","&","^","%","$","#",
            "@","!","`","~"]

numbers = ["1","2","3","4","5","6","7","8","9","0"]

strength=0

if any(num in password for num in numbers):
    strength+=1

if any(sc in password for sc in special_characters):
    strength+=1

if any(uc in password for uc in uppercase_letters):
    strength+=1

if any(lc in password for lc in lowercase_letters):
    strength+=1

if len(password)<8:
    strength = -100
    print("password is too short")
elif len(password)<33 and len(password)>=8:
    if len(password)>=8 and len(password)<17:
        strength += 1
    elif len(password) >= 17 and len(password) < 25:
        strength += 2
    elif len(password) >= 25 and len(password) < 33:
        strength += 3
else:
    print("password is too long bruh")

if strength==1 or strength ==2:
    print("Password is very weak")

if strength==3:
    print("Password is weak")

if strength==4:
    print("Password is ok")

if strength==5:
    print("Password is strong")

if strength==6 or strength==7:
    print("Password is very strong")