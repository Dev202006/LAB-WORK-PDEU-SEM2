# Writing to a text file
file = open("example.txt", "w")
file.write("Hello, this is a sample text file.\n")
file.write("This file demonstrates basic file handling in Python.\n")
file.close()

# Reading from a text file
file = open("example.txt", "r")
content = file.read()
print("File Content:")
print(content)
file.close()
#other way: 

with open("example.txt","w") as file: 
    lines = ['hey this is another sample text file\n','we have tried to write it in one go\n']
    file.writelines(lines)

file = open("example.txt", "r")
lines = file.readlines()
print("\n\n\nFile Content (Line by Line):")
for line in lines: 
    print(line.strip())
file.close()


# Appending to a text file
file = open("example.txt", "a")
file.write("\n\nThis line is appended to the file.\n")
file.close()

# Reading the updated file
with open("example.txt", "r") as file: 
    while True:
        line = file.readline()
        if not line:
            break
        print(line.strip())