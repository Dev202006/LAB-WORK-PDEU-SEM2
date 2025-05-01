import os,time,shutil
print ("OS Name:", os.name)
print (os.getcwd())
print (os.listdir('.'))
print (os.listdir('..'))

if os.path.exists('some directory that doesn not exist'): 
    print("wow miracle. directory exists")
else: 
    os.mkdir("lmao new directory")

    os.chdir("lmao new directory")
    if os.path.exists('.\\dir1\\dir2\\dir3'): 
        os.chdir(".\\dir1\\dir2\\dir3")
    else: 
        os.makedirs(".\\dir1\\dir2\\dir3")
        f = open("myfile.txt","w+")
        f.write("Hi, learn python file handling in simple manners\n")
        f.close()
        stats = os.stat("myfile.txt")
        print("Size = ",stats.st_size)
        os.rename("myfile.txt","yourfile.txt")
        shutil.copyfile("yourfile.txt","our")
        os.remove("yourfile.txt")
        curpath = os.path.abspath('.')
        file_path = os.path.join(curpath, 'yourfile.txt')
        if os.path.isfile(file_path):
            print('Yourfile file does exist.')
        else:
            print('Yourfile file doesn\'t exist.')
        file = 'ourfile.txt'
        print(file)
        created = os.path.getctime(file)
        modified = os.path.getmtime(file)
        accessed = os.path.getatime(file)

        print("Date created: ",time.ctime(created))
        print("Date modified: ",time.ctime(modified))
        print("Date accessed: ",time.ctime(accessed))
        