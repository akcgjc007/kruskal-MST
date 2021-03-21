import os
from time import time
import matplotlib.pyplot as plt 

X = []
Y = []

# for i in range(1, 10):
#     os.system("make p=50 n="+str(i*10))

f = open("./data.txt", "r")
for line in f:
    l = line.split(',')
    Y.append(int(l[0]))
    X.append(int(l[1]))

plt.title('Comparison of elapsed time vs total no. of nodes in the graph')
plt.xlabel('Increasing probability') 
plt.ylabel('Increasing no. of nodes in the graph')
plt.plot(X, Y)
# plt.show()
plt.savefig('./img/img.png', dpi=300)