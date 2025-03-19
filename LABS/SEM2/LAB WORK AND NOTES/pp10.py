'''
Write a program that defines a functino called frequency() which computes the frequency of words present in a string passed to it.
The frequencies should be returned in sorted order out of words in the string. 
'''
def frequency(s): 
    slist = s.split(" ")
    sset = set(slist)
    mydict = {}
    for i in sset: 
        mydict[i] = slist.count(i)
    sorted_dict = sorted(mydict.items(), key=lambda item: item[1])
    print(sorted_dict)

s = input("Enter a string: ")
frequency(s)

