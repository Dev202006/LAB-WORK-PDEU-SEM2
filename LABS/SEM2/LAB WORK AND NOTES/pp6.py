def func(n): 
    l = []
    for x in range(1,n+1):
        l.append((x,x**2,x**3))
    print(l)

n = int(input("Enter limit: "))
func(n)
