
a = 4 + 3j
b = 3 - 2j
print(a,type(a))
print(b,type(b))

c = a+b 
d = a-b
e = a*b
f = a/b
print(c,d,e,f)


''' how to define your own class that uses i instead of j? '''

class xcomplex: 
    #we call the functions within class as methods
    def __init__(self, r= 0, i = 0): #constructor method//default always called no matter what ... if specific values given then those exist 
        ''' self kya hai? 
        uske andar woh memory address jane wala hai so, when called it goes like: xcomplex(memory,r,i)
        '''
        self.real = r
        self.imaginary = i
    def display(self,n=1): 
        for i in range(n): 
            print(f'{self.real}{self.imaginary:+}i') #by default gives plus sign , and if other, then gives other

    def __str__(s): #magic method 
        return (f'{s.real}{s.imaginary:+}i') #by default gives plus sign , and if other, then gives other

    def __add__(self, other): 
        return xcomplex(self.real+ other.real,self.imaginary + other.imaginary)
    def __sub__(self, other): 
        return xcomplex(self.real- other.real,self.imaginary - other.imaginary)
    '''
    other way: 
        ans = xcomplex()
        ans.r = self.r + other.r
        ans.i = self.i + other.i
    '''
    #similarly you can do the following: 
    def __mul__(self,other): 
        ans = xcomplex()
        a1 = self.real
        a2 = other.real
        b1 = self.imaginary
        b2 = other.imaginary
        ans.real = a1*a2 - b1*b2
        ans.imaginary = a1*b2 + b1*a2
    
        return ans
    def mod(self): 
        return (self.real)**2 + (self.imaginary)**2
    def __truediv__(self,other): #for division it's always 'truediv'
        ans = xcomplex()
        a1 = self.real
        a2 = other.real
        b1 = self.imaginary
        b2 = other.imaginary
        ans.real = (a1*a2 + b1*b2)/other.mod()
        ans.imaginary = (b1*a2 - a1*b2)/(other.mod())
        return ans
    def __eq__(self,other): 
        a1 = self.real
        a2 = other.real
        b1 = self.imaginary
        b2 = other.imaginary
        if a1 == a2 and b1==b2: 
            return True
        else: 
            return False
        



print("This is a program that defines a complex class and lets you perform basic arithmatic and logical operations: ")
a1 = int(input("Enter the first complex number...\nEnter real part: "))
b1 = int(input("Enter imaginary part: "))
a2 = int(input("Enter hte second complex number...\nEnter real part: "))
b2 = int(input("Enter imaginary part: "))
z1 = xcomplex(a1,b1)
z2 = xcomplex(a2,b2)
z1.display()
z2.display()

while True: 
    print("Press...\n'a' for addition \n's' for subtraction (z1-z2)\n'mm' for multiplication\n'd' for division(z1/z2)\n'm' for modulus (|z1|,|z2|)\ntype 'xxx' to exit")
    user = input("Type the input: ").lower()
    if user == "xxx": 
        break
    elif user == 'a': 
        print(z1 + z2)
    elif user == 's': 
        print(z1-z2)
    elif user == 'mm': 
        print(z1*z2)
    elif user == 'd': 
        print(z1/z2)
    elif user == 'm': 
        print(f"({z1.mod()},{z2.mod()})")
    else: 
        print("Wrong input. Try Again...")