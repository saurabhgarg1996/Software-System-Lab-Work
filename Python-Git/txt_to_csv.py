import re, csv

txt_file = "tenth.txt"
csv_file = "cbseProccessed.csv"
li = open(txt_file)

# in_txt = csv.reader(open(txt_file, "rb"), delimiter = "\t")
out_csv = csv.writer(open(csv_file, 'w'),dialect='excel')

content = li.readlines()
count=1
flag=1;
mod_list=[]
mod_l=[]
mod_list=["ROLL_NO CANDIDATE_NAME  SUB MRK  GRD  SUB MRK  GRD  SUB MRK  GRD  SUB MRK  GRD  SUB MRK  GRD  RSLT CGPA  Part IA Part IA Part IA Part 2A Part 2C Part 2D Part 2D Part 2D Part 2D  Part 3A Part 3A Part 3B Part 3B ADDL.SUB"]
for line in content :
	if line[0]=='R':
		s=list(line)
		for i in range(0,22):
			if(flag==1) and line[i]==" ":
				s[i]="_"
				flag=0
			elif line[i]==" ":
				flag=1
				s[i]=","
		for i in range(22,len(line)):
			if s[i]==".":
				s[i]=" "
			elif(s[i]==" "):
				while(s[i]==" "):
					i=i+1
				s[i-1]=','
			if(s[i]=='\n'):
				s[i]=" "
		mod_l="".join(s)
		mod_l = mod_l+",Part_2A"
		mod_l = mod_l+",,,,,,"
		mod_l = mod_l+"Part_2B"
		mod_l = mod_l+","
		mod_l = mod_l+",Part_2C"
		mod_l = mod_l+","
		mod_l = mod_l+",Part_2D,"
		mod_l = mod_l+",,,,,,"
		mod_l = mod_l+",Part_3A,"
		mod_l = mod_l+",,"				
		mod_l = mod_l+",Part_3B,"
		out_csv.writerow(mod_l.split(','))
		break



for line in content:
    # strip ending whitespaces including newline char
    line = line.rstrip()
    # concatenate every two lines
    if count % 2 == 0:
        mod_list.append(old_line+line)
    else:
        old_line = line
    count += 1
content = mod_list
#out_csv.writerow(mod_list[0].split())
for lines in content :
	if(lines[0].isdigit()):
		s=list(lines)
		for i in range(9,35):
			if lines[i]==" " and lines[i+1]!=" ":
				s[i]="_"
		lines="".join(s)
		lines=lines.split()
		#print lines[18]
		for i in range(1,18):
			if lines[i]=="EIOP":
				lines.insert(i+1,"NA")
		out_csv.writerow(lines)

# with open("tenth.txt") as fp_in, open("cbseProccessed.csv", "wb") as fp_out:
#     writer = csv.writer(fp_out)
#     for line in fp_in:
#         row = re.split("\s\s+", line.strip())
#         writer.writerow(row)

# #         
# file = open('tenth.txt', 'r')
# text=file.read()
# text = re.sub('[^a-zA-Z\ \']+', " ", text)
# words = list(text.split())
# print words
