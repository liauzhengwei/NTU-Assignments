#input group and ID, get the score

#Student = [Group, ID, Score]
Data = [["FE1",5,44],["FE2",2,66]]

Group = "FE2"
ID = 2

#Query Grades
#for i in Data:
 #   if i[0] == Group and i[1] == ID :
  #      print(i[2])

#List grades
#abc = []
#for i in Data:
   #if i[0] == Group:
      #abc.append(i[2])
#print(abc)

abc = [44, 66, 100, 77, 3, 10]

#Max grade
while len(abc)!=1:
    if abc[len(abc)-1] <= abc[len(abc)-2]:
        abc.pop()
    else:
        abc.remove(abc[len(abc)-2])
print(abc)



