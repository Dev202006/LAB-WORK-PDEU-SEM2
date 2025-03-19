def largestandsmallestoutofthree(a:int,b:int,c:int)->int:
    if a>=b>=c: 
        print(a,'is the largest') 
    elif b>=a>=c: 
        print(b,'is the largest')
    else: 
        print(c,'is the largest')

a = int(input("Enter a number: "))
b = int(input("Enter a number: "))
c = int(input("Enter a number: "))
largestandsmallestoutofthree(a,b,c)
