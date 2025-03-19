'''
Write a function create_list() that creates and returns a list which is an intersection of two lists passed into it
'''
import json
def create_list(l1,l2): 
    s1 = set(l1)
    s2 = set(l2)
    s = s1.intersection(s2)
    l = list(s)
    return l 
l1 = json.loads(input("Enter list in JSON format: "))
l2 = json.loads(input("Enter another list in JSON format: "))
l = create_list(l1,l2)
print(l)

