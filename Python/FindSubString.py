#This script find a certain substring within a string, and counts how many times it appears 



def count_substring(string, sub_string):
    aux = 0
    for i in range(0, len(string), len(sub_string)-1):
        #print(i)
        if (i + len(sub_string) - 1 ) < len(string):
            if i > 0: 
                if i + len(sub_string) >= len(string) - 1:
                    #print(string[i:i+len(sub_string)+1])
                    if sub_string in string[i:i+len(sub_string)+1]:
                        aux = aux + 1
                        #print(aux)
                else:
                    #print(string[i:i+len(sub_string)])
                    if sub_string in string[i:i+len(sub_string)]:
                        aux = aux + 1
                        #print(aux)
            else: 
                #print(string[i:i+len(sub_string)])
                if sub_string in string[i:i+len(sub_string)]:
                    aux = aux + 1
                    #print(aux)
    return aux

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
