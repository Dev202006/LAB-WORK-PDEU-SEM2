'''
TO CREATE A 3-D list in the form create_array(3,4,5,n)

'''

def create_array(l,b,h,n): 
    final = []
    for i in range(h): 
        listb = []
        for j in range(b): 
            listl = []
            for k in range(l): 
                listl.append(n)
            listb.append(listl)
        final.append(listb)
    return final 
l = int(input("Enter length: "))
b = int(input("Enter breadth:" ))
h = int(input("Enter height: "))
n = int(input("Enter elemeent: "))

print(create_array(l,b,h,n))


