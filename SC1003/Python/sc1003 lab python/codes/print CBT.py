t=[[[5],8,[4]],6,[[5],2,[1]]]

def printTree(t, level):
    if len(t)==1:
        print(" " * level,end="")
        print(t[0])
    else:
        printTree(t[2], level+1)

        print(" "* level,end="")
        print(t[1])

        printTree(t[0],level+1)

printTree(t,0)
