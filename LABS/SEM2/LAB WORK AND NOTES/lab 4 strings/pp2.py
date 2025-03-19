def caseconvert(sx): 
    user = input("Enter U/L/T for upper, lower and toggle case: ")
    if user == "U": 
        for i in range(len(sx)): 
            if sx[i].isalpha():
                sx = sx.replace(sx[i],str(chr(ord(sx[i]) -32)))
        print(sx)
    elif user == "L": 
        for i in range(len(sx)): 
            if sx[i].isalpha():
                    sx = sx.replace(sx[i],str(chr(ord(sx[i])+32)))
        print(sx)
    elif user == "T": 
        if ord(sx[0])>= 97 and ord(sx[0]) <= 122: #all must be now small
            for i in range(len(sx)): 
                if sx[i].isalpha() and ord(sx[i])>=65 and ord(sx[i])<= 90:
                    sx = sx.replace(sx[i],str(chr(ord(sx[i])+32)))
        elif ord(sx[0])>=65 and ord(sx[0])<= 90: 
            for i in range(len(sx)): 
                if sx[i].isalpha() and ord(user[i])>= 97 and ord(user[i]) <= 122:
                    sx = sx.replace(sx[i],str(chr(ord(sx[i])-32)))
        print(sx)

    return 0

caseconvert(input("Enter a sentence: "))