txt = "Welcome"
#function to return prime number list: 
def prime(limit):
    primelist = []
    def checkprime(n):
        check = True
        for i in range(2,n): 
            if n%i == 0: 
                check = False
        return check
    n = 5
    while len(primelist)<=limit: 
        if checkprime(n): 
            primelist.append(n)
        n+=1
    return primelist

def encrypt(txt):
    primelist = prime(len(txt)*2)
    newtxt = ""
    for ch in txt: 
        ch = ord(ch)
        en = ch + primelist.pop(0) - primelist.pop(0)
        newtxt += chr(en)

    print(newtxt)

encrypt(txt)

                

                




