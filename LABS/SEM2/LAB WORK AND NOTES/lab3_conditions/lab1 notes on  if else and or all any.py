#all() and any() gives the same as joining everything with and and or respectively
# all and any give only bullion values 
a,b,c = 10,20,30
x = a>5 and b>5 and c>45
print(x)
x = all((a>5,b>5,0))
print(x)
x = any((a<5,b<5,25,c>45))
print(x)
x = a<5 or b<5 or 25 or c >45
print(x)