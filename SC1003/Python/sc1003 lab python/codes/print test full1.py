import random as r

#print("Python",'1003', sep='~', end='#')
#print('Have',"fun")

#print('Hi'+"Python"+'1003')

#print('Hi'+"Python"+str(1003), sep="$")

#string = "Sifon"
#a = string[::-1]
#b = string[0:14:-1] +"y"
#print(a)
#print(b)

#print(range(9,3,-3))
#print(list(range(9,3,-3)))
#----------------------------------------------------------------------------------------------------------------------

#list1 = ['d','c','A',3]
#list2 = ['A','b','3']
#list1.reverse()
#list2.reverse()

#list3 = list1.extend(list2)
#result = [item for item in list1 if item in list2]

#print(list3)
#prints None

#print(result)
#prints "A"

#----------------------------------------------------------------------------------------------------------------------
#x = "awesome"
#def myfunc():
#  global x
#  x = "fantastic"

#myfunc()

#print("Python is " + x)

#----------------------------------------------------------------------------------------------------------------------
nums = [1,2,3,4]
output = []

for i in range(0, len(nums)):
    result = 0
    while i >=0:
        result += nums[i]
        print(result)
        i-=1
    output.append(result)
    print(output)

