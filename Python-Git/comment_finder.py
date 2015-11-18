import sys
import re

if len(sys.argv) <= 1 or len(sys.argv) > 2 :
	print("Wrong number of arguments")
	sys.exit()

filename = sys.argv[1]

f = open(filename, "r")
f2 = open("test_code_out.txt", "w")
content = f.readlines()
flag = False
s = 2
str=""
for line in content:

	for i in range(1, len(line)-1):
		if line[i] =='/' and line[i+1] =='/':
			str = line[i:len(line)]
			f2.write(str)
			#f2.write('\n')
			str = ""
			break
		elif line[i] == '*' and line[i+1] =='/' and flag==True:
			flag = False
			str+='*'
			str+='/'
			f2.write(str)
			f2.write('\n')
			str = ""
		elif (line[i] == '/' and line[i+1] =='*') or flag==True:
			flag = True
			if(line[i]==" " and line[i+1]==" "):
				continue
			if(line[i]==" " and line[i-1]==" "):
				continue
			str+=line[i]
			if (i == len(line)-2):
				str+='\n'
		else:
			s = s;

f2.close()



