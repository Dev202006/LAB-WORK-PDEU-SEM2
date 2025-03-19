'''
Write ap rogramt hat defines a function convert() that receives a string containing a sequence of whitespace separated words and returns a string after removing all duplicate words and sorting them alphanumerically. 
Use set list, sorted, join

'''
from string import *
def convert(s1):
    #make a list of words using split
    s = s1.split(" ")
    #remove duplicates using set
    #make a sorted list
    s = sorted(set(s))
    #join to a character sentence
    fstring = " ".join(s)
    print("The final string is: \n",fstring)

s1 = input("Enter string: ")
convert(s1)



