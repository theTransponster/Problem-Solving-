#This is a brief code to change lower cases in a string, to upper cases and vice versa 
#This kind of algorith can be useful to encryption applications 

def swap_case(s):
    newString = ''
    for i in range(0, len(s)):
        if s[i] > = 'a' and s[i] < = 'z':
            newString = newString + s[i].upper()
        elif s[i] > = 'A' and s[i] < = 'Z':
            newString = newString + s[i].lower()
        else:
            newString = newString + s[i]
    return newString

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
