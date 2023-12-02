classOneGrades = [12,43,55,87,99,88,13,45]
classTwoGrades = [36,54,77,86,16,32,4,58,100,100,100,100,100]

def average(grade):
    count = 0
    Total = 0

    while count<len(grade):
        a = grade[count]
        Total+=a
        count+=1

        avg = float(Total/len(grade))
    print(avg)
    return avg

classOneAverage = average(classOneGrades)
classTwoAverage = average(classTwoGrades)

if classOneAverage > classTwoAverage:
    print("Class One has a higher average score!")
elif classTwoAverage > classOneAverage:
    print("Class Two has a higher average score!")
else:
    print("They both have the same average score!")

def max_score(grades):
    while len(grades)!=1:
        if grades[len(grades)-1]<=grades[len(grades)-2]:
            grades.pop()
        else:
            grades.remove(grades[len(grades)-2])
    print(grades)
    return grades

classOneMax = max_score(classOneGrades)
classTwoMax = max_score(classTwoGrades)

if classOneMax > classTwoMax:
    print("Class One has a higher max score!")
elif classTwoMax > classOneMax:
    print("Class Two has a higher max score!")
else:
    print("They both have the same max score!")



