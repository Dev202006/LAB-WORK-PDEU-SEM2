def stringremove(parent,child): 
    if child in parent: 
        #we will try to remove the child string from the parent string
        size = len(child)
        for i in range(len(parent)): 
            if parent[i:i+size] == child: 
                parent = parent.replace(parent[i:i+size],"")
        print(parent,"is the new string without the child string")
    else: 
        print("The second string is not present in the first string")
    return 0

stringremove(input("Enter the first string: "), input("Enter the second string: "))