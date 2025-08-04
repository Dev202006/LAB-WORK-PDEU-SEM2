from random import randint 
s = set()
while len(s)<10: 
    s.add(randint(15,45))
print(*s)
print()

remove_list = []
for i in s: 
    
    if i > 30: 
        remove_list.append(i)

for i in remove_list: 
    s.remove(i)
print(*s)