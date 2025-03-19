def numberofdigits(a):
    if a<10:
        print("1 digit")
    elif a<100: 
        print("2 digit")
    elif a<1000: 
        print("3 digit")
    else: 
        print("more than 3 digit")
a = int(input("Enter a number: "))
numberofdigits(a)