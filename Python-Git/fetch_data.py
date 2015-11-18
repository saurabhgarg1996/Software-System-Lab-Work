import csv
import math
import os
import random, sys
import re

count=0
if len(sys.argv) != 2:
	print('Wrong input arguments')
	print('Use: python3 fetch_data.py <filename>')
	sys.exit()

list_of_list=[]
filtered=[]
with open(sys.argv[1]) as csvf:
	row = csv.reader(csvf, delimiter=' ', quotechar='|')
	for myrow in row:
		if (myrow[0][0]>="0" and myrow[0][0]<="9"):
			count=count+1
			str1 = "".join(myrow[0])
			list1 = str1.split(',')
			list_of_list.append(list1)

with open(sys.argv[1]) as csvf:
	row = csv.reader(csvf, delimiter=',', quotechar='|')
	for myrow in row:
		if (myrow[0]=="\"Sno\""):
			zipped=zip(myrow,range(1,len(myrow)+1))
			headings=dict(zipped)
		

print(count)
print(len(list_of_list))
filtered = filter(lambda l: l[-1] == '1', list_of_list)
print(len(list(filtered)))
	
for keys,values in headings.items():
	print(keys , ":" , values)

for list in list_of_list:
	total=0
	for i in range(1,6):
		if list[i]=="\"NA\"" :
			list[i]="NA"
			total=total
		else: 
			total=total+float(list[i])
	list.append(total)

list_of_list.sort(key=lambda x: -x[7])

start_list=[]
with open(sys.argv[1]) as csvf:
	row = csv.reader(csvf, delimiter=',', quotechar='|')
	for myrow in row:
		if(myrow[0]=="\"Sno\""):
			myrow.append("total_marks")
		if(myrow[0][0]<"0" or myrow[0][0]>"9"):
			start_list.append(myrow)

for i in range(0,7):
	start_list[0][i].replace("\"","")	

with open("marks_sorted.csv", "w") as f:
    writer = csv.writer(f)
    writer.writerows(start_list)

with open("marks_sorted.csv", "a") as f:
    writer = csv.writer(f)
    writer.writerows(list_of_list)


