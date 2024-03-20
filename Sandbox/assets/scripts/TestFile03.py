# From : https://www.tutorialspoint.com/generating-random-number-list-in-python

import random
randomlist = []
for i in range(0,5):
n = random.randint(1,30)
randomlist.append(n)
print(randomlist)