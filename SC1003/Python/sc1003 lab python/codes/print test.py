astr = "w50qwer"
newstr = astr[:]
print(newstr)
newstr = '111'.join(astr)
print(newstr)
newstr = astr[0:14:-1]
print(newstr + "a")

newstr = astr + "gggas"
print(newstr)

newstr = astr*3
print(newstr)

newstr = astr.upper()
print(newstr)

#b = ['a',0,"p"][1]
#print(b + "po")      #error

b = ['p'][-1]
print(b)

b = ['a',0,4,88,"p"]
#print(sum(b))  #error
b = b.pop(3)
print(b)

b = ['a',0,4,88,"p"]
b = b*3
#b = b.insert(-1,"r")
print(b)

b = ['a',0,4,88,"p"]
b.append("s")
print(b)

f = "iwagffd hbkjhb fafw"#.split()
f = f.split()
print(f)

b = ['a',0,4,88,"p"]
b.extend([-1,"r"])
print(b)

b = ['a',0,4,88,"p"]
b = b.remove("p")
print(b)

b = ['p',"d"]
b.sort()
print(b)

b = [0,4,88,9]
b = b.reverse()
print(b)

print("i")
print("jkndkjn",end="\n ")
print("o")

#reverse a tuple
w = ("r","u",9,22)
w = reversed(w)
w = tuple(w)
print(w)

t = {"y" : 8,
    "r" : 7}
del t["y"]
print(t)
del t["r"]
print(t)


print("---",format(1.23456, "10.2%"))