def ispalindrome(s):
    if s == s[::-1]:
        print("IT IS PALINDROME")
    else: 
        print("IT IS NOT PALINDROME")
s = input("Enter a string: ")
ispalindrome(s)