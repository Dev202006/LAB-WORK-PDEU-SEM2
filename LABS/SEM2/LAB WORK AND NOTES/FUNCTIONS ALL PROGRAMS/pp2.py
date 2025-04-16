'''
WRITE A RPOGRAM THAT DEFINES A FUNCTION COMPUTE() THAT 
CALCULATES THE VALUE of n + nn + nnn + nnnn, where n is a digit recieved by the function. test the function for digits 4 to 7. 
'''

def compute(n):
    dig = str(n)
    sum = int(dig)+ int(dig*2) + int(dig*3) + int(dig*4)
    return sum

for i in range(4,8):
    print("the answer for",i,"is",compute(i))