data = [
    ["ID", "Name", "Age", "Department", "GPA"],
    [1, "Alice", 20, "Computer Science", 3.8],
    [2, "Bob", 21, "Mechanical", 3.4],
    [3, "Charlie", 22, "Electrical", 3.6],
    [4, "Diana", 20, "Civil", 3.9],
    [5, "Ethan", 23, "Chemical", 3.2]
]
#writing data in the csv file

with open('csv.csv','w') as f:
    lines = []
    for row in data: 
        line = ','.join([str(element) for element in row])+'\n' 
        lines.append(line)
    f.writelines(lines)

        

#reading data in the csv file to a list

newdata = []
with open('csv.csv','r') as f: 
    lines = f.readlines()
    for line in lines: 
        row = line.strip().split(',')
        newdata.append(row)
print(newdata)
'''
  
#using writer and reader objects
import csv

with open('newcsv.csv','w',newline="" ) as f: 
    writer = csv.writer(f)
    for row in data: 
        writer.writerow(row)
    #or writer.writerows(data)


d_data = [
{"ID": 1, "Name": "Alice", "Age": 20, "Department": "Computer Science", "GPA": 3.8},
{"ID": 2, "Name": "Bob", "Age": 21, "Department": "Mechanical", "GPA": 3.4},
{"ID": 3, "Name": "Charlie", "Age": 22, "Department": "Electrical", "GPA": 3.6},
]
heading = list(d_data[0].keys())
#make a mechanism to get the student details from user. 
with open('newcsv.csv','w',newline="" ) as f: 
    writer = csv.DictWriter(f,fieldnames = heading)
    writer.writeheader()
    writer.writerows(d_data)
with open('newcsv.csv','r') as f: 
    for row in csv.reader(f): 
        print(row)
    print('now printing using dictreader')
    f.seek(0,0)
    d = []
    for row in csv.DictReader(f):
        d.append(row)
id = input("Enter ID of studetn who's detail you want: ")
for row in d: 
    if row['ID'] == id: 
        print(row)
        '''