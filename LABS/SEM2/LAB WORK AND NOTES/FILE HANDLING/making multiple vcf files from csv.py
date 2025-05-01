contacts = [
    ["Sr.No", "Name", "Phone", "Email"],
    [1, "Alice Johnson", "9876543210", "alice.johnson@example.com"],
    [2, "Bob Smith", "9123456780", "bobsmith92@example.com"],
    [3, "Charlie Davis", "9988776655", "charlied@example.org"],
    [4, "Diana Parker", "9090909090", "diana.parker@example.net"],
    [5, "Ethan Moore", "9871234567", "ethan.moore@example.com"],
    [6, "Fiona Clarke", "8765432190", "fiona.c@example.com"],
    [7, "George Lewis", "9345678901", "george.lewis@example.net"],
    [8, "Hannah Baker", "9223344556", "h.baker@example.org"],
    [9, "Ian Scott", "9445566778", "ianscott@example.com"],
    [10, "Jenny Lee", "9334455667", "jenny.lee@example.com"],
    [11, "Kevin Wright", "9556677889", "kevin.wright@example.net"],
    [12, "Linda Hall", "9111222333", "linda.hall@example.com"],
    [13, "Martin King", "9221234567", "m.king@example.org"],
    [14, "Nina Adams", "9445566123", "nina.adams@example.com"],
    [15, "Oscar Bell", "9334412345", "oscar.bell@example.net"],
    [16, "Paula Green", "9211334455", "paula.green@example.org"],
    [17, "Quentin Reed", "9667788990", "q.reed@example.com"],
    [18, "Rachel Young", "9123456677", "rachel.young@example.net"],
    [19, "Steve Turner", "9788899001", "stevet@example.org"],
    [20, "Tina Cook", "9322114455", "tina.cook@example.com"]
]

#first we'll write into a csv file

import csv 
with open('contacts.csv','w',newline = "") as f: 
    writer = csv.writer(f)
    writer.writerows(contacts)

#now we'll make vcf files for each

with open('contacts.csv','r') as f: 
    reader = csv.DictReader(f)
    keys = reader.fieldnames
    print(keys)
    for contact in reader:  
        name = contact['Name']
        phone = contact['Phone']
        email = contact['Email']
        with open(f"contact{contact['Sr.No']}.vcf",'w') as f2: 
            f2.write("BEGIN:VCARD\n")    
            f2.write("VERSION:3.0\n")
            f2.write(f"FN:{name}\n")
            f2.write(f"TEL;TYPE=CELL:{phone}\n")
            f2.write(f"EMAIL:{email}\n")
            f2.write(f"END:VCARD")

'''
BEGIN: VCARD
VERSION:3.0
FN: name 
TEL;TYPE = CELL: xxxxxxx
EMAIL: name@domain.com
END: VCARD

'''