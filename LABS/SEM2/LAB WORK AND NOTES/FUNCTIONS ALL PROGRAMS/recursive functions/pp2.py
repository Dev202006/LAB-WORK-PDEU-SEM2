#find the binary equivalent of a number using recursion

def bin(num): 
    num = abs(num)
    if num >0: 
        return bin(num//2)*10 + num%2
    else: 
        return 0


print(bin(int(input("Enter a number you want to find the binary of : ")))) 