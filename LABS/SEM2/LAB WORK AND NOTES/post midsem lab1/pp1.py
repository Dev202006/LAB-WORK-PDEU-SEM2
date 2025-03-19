'''
WRITE A PROGRAM THAT DEFINES A FUNCTION COUNT_LOWER_UPER() THAT ACCEPTS A STRING AND CALCULATES THE NUMBER OF UPPERCASE AND LOWERCASE ALPHABET IN IT
IT SHOULD RETURN THESE VALUES AS A DICTIONARY. CALL THIS FUNCTION FOR SOME SAMPLE STRING
'''
def count_lower_upper(s): 
    upper = lower = 0
    for c in s: 
        if c >= 'a' and c<= 'z': 
            lower +=1 
        elif c>='A' and c<='Z': 
            upper +=1
    return {'u':upper,'l': lower}

s = input('Enter a string: ')
count = count_lower_upper(s)
print("Number of upper case characters:",count['u'])
print("Number of lower case characters:",count['l'])