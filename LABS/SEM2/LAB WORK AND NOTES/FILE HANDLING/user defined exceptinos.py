class NumTooSmall(Exception):
    def __init__(self, arg):
        self.msg = arg
        print ("Inside NumTooSmall")

class NumTooBig(Exception):
    def __init__(self, arg):
        self.msg = arg
        print ("Inside NumTooBig")

def try6():
    d = {}
    for x in range(10):
        try:
            a = int(input("Enter a number:"))
            d[a] = a*a*a
            if a < 3:
                raise NumTooSmall(a)
            elif a > 30:
                raise NumTooBig(a)
        except ValueError:
            print("Error")
        except NumTooSmall as me:
            print (a , "<3")
        except NumTooBig as me:
            print (a , ">10")
            
    print ("now in try6 ...")
    print (d)
try6()
