import matplotlib.pyplot as plt
import csv
n =[]
time = []
with open("data.csv") as csvf:
	row = csv.reader(csvf, delimiter=',', quotechar='|')
	for line in row:
		# print(line)
		# print("A")
		n.append(line[0])
		time.append(line[2])


plt.plot(n, time, 'ro', label='Graph of fibo')
plt.xlabel('n')
plt.ylabel('Time')
plt.legend( loc='upper left', numpoints = 1 )
#plt.axis([0, n[-1], 0, time[-1]])
plt.show() 
