width = int(input("Please enter pattern width: "))

n=1

for i in range(2*width):
    if i>=(width+1):
        print((i-2*n)*"*")
        n +=1
    else:
        print(i*"*")

