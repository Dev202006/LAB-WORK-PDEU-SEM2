'''
COUNT HOW MANY VOWELS ARE THERE IN A STRING. ACCEPT THE STRING FROM THE USER
'''

def countv(sx): 
    count = 0 
    for letter in sx: 
        if letter in "AEIOUaeiou":
            count +=1
    return count
sx = input("Bolo kuch: ")
vowels = countv(sx)
print("Tum itne vowels bole: ",vowels)