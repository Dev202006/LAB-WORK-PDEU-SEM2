import json
f = open('Sampledata.json','w+')
lst = [10, 20, 30, 40, 50, 60, 70, 80, 90]
json.dump(lst,f)
f.seek(0)
inlst = json.load(f)
for i in inlst:
    print(i)
print(sum(inlst))
f.close()
