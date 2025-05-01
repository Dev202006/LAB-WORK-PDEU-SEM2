
'''f = open("example.txt","rb")
print(f.tell())
f.read(5)
pos = f.tell() # position after reading 5 character
print(pos)
f.seek(0,0) # goes back to the start
print(f.tell()) # 0
f.seek(pos,1) #goes to the 5th character
f.seek(-pos,1)#goes to the start
print(f.read(5).decode())#prints first character
f.close()

f = open("example.txt","r")
while True:
    x = f.readline()
    print(x,end = "")
    if not x: 
        break

try:
    f = open("filedoesn'texist.txt","r")
    print(f.read())
    f.close()
except FileNotFoundError: 
    print("FILE DOESN'T EXIST")
'''

#PROGRAM TO COPY THE CONTENT OF ONE FILE INTO ANOTHER

flname = input("Enter the name of the file you want to copy from: ")
with open(flname,"r") as f: 
    content = f.read()
flname2 = input("Enter the name of the file you want to copy to: ")
with open(flname2,"w+") as f2: 
    f2.write(content)
    f2.seek(0)
    print(f2.read())
