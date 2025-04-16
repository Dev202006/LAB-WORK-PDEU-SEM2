def ispangram(s): 
    s_set = set((s.upper()).strip())
    alphaset = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    if alphaset.issubset(s_set): 
        print("It is a pangram")
    else:
        print("It is not a pangram")

s = input("Enter a sentence: ")
ispangram(s)