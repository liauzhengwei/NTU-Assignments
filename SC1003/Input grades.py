groups=[]

NumberOfGroups = int(input("Enter number of groups: "))
print("The groups are ",end="")
for i in range(1,NumberOfGroups+1):
    i = str(i)
    a = "FE" + i
    groups.append(a)
print(groups)

Data = []
NumberOfStudents = 40

while len(Data)<2: #NumberOfStudents:
    Group = input("Enter a group: ")
    if Group not in groups:
        print("Enter FE1,FE2 etc.")
        continue

    ID = input("Enter an ID no.(1-40): ")
    ID = int(ID)
    if ID<1 or ID>40:
        print("Enter a number between 1-40!!!")
        continue

    Score = input("Enter a score: ")
    Score = int(Score)
    if Score<1 or Score>100 :
        print("Enter a number between 1-100!!!")
        continue

    ID = str(ID)
    Score = str(Score)
    Student = [Group,ID,Score]
    Data.append(Student)
    #print(len(Data))



print(Data)
