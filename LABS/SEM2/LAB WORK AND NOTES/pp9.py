'''
Write a program that defines a function count_alpha_digits()that accepts a string and calcualtes the number of alphabets and digits in it . i
t should return these values as a dictionary
'''

def count_alpha_digits(s): 
    slist = list(s)
    dictionary = {'a':0,'d':0}
    for i in slist: 
        if i.isalpha(): 
            dictionary['a'] +=1 
        elif i.isdigit(): 
            dictionary['d'] +=1
    return dictionary

s = input("Enter string: ")
d = count_alpha_digits(s)
print("Alphabets: ",d['a'],"Digits: ",d['d'])


