def divby10(a:int):
    if a%10: 
        print("Not divisible by 10")
    else: 
        print("Divisible by 10")

a = int(input("Enter a number: "))
divby10(a)
