'''Write a program that receives an integer an input.
 If a string is entered instead of an integer, then report an error and give another chance to user to enter an integer. 
 Continue this process till correct input is supplied.
'''

d = {1:2,2:3,3:4}
def ask(): 
    try: 
        x = int(input('Enter an integer: '))
        print(d[x])
    except ValueError: 
        print("Add an integer not a string")
        ask()
    except KeyError: 
        print("key error lag raha hai")

ask()