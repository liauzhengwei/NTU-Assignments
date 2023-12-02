#==================================================================================================
#qn3

def reverser(a_str):
   if len(a_str) == 1:
        return a_str

   else:
        new_str = reverser(a_str[1:]) + a_str[0]
        return new_str

def symmetricString(a_str):
    if len(a_str) == 1:
        return a_str*2

    else:
        new_str = reverser(a_str[1:]) + a_str[0]
        return a_str + new_str




a_str = "Afsyo"

str1 = symmetricString(a_str)

print(str1)

#==================================================================================================
#qn2

def reverser(a_str):
   if len(a_str) == 1:
        return a_str

   else:
        new_str = reverser(a_str[1:]) + a_str[0]
        return new_str

def reverseAndOppositeCase(a_str):
   if len(a_str) == 1:
        return a_str

   else:
        new_str = reverser(a_str[1:]) + a_str[0]
        endstr = ""
        for i in new_str:
            if i.isupper() == True:
                a = i.lower()
                endstr += a
            else:
                b = i.upper()
                endstr += b
        return endstr

#a_str = "AfVsmofpDo"
#str1 = reverseAndOppositeCase(a_str)

#print(str1)

#==================================================================================================
#qn1

def reverser(a_str):
   if len(a_str) == 1:
        return a_str

   else:
        new_str = reverser(a_str[1:]) + a_str[0]
        return new_str

def reverseAndRepeat(a_str, num):
   if len(a_str) == 1:
        return (a_str *num)

   else:
        new_str = reverser(a_str[1:]) + a_str[0]
        endstr = ""
        for i in new_str:
            a = i*num
            endstr += a
        return endstr

#a_str = "AfDo"
#str1 = reverseAndRepeat(a_str, 4)

#print(str1)