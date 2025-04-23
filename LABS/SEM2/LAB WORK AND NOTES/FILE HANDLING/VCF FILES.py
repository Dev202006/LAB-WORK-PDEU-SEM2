f = open(r"D:\Documents\PDEU-SEM-1-2\LABS\SEM2\LAB WORK AND NOTES\1.vcf","w+")
name = "Darshit sir Computer PDEU"
mob = "9825974525"
email = "darshit.shah@spt.pdpu.ac.in"
f.write("BEGIN:VCARD\n")
f.write("VERSION:3.0\n")
f.write("FN:"+name+'\n')
f.write("TEL;TYPE = CELL:"+mob+'\n')
f.write("EMAIL:"+email+'\n')
f.write("END:VCARD\n")