import math 

for i in range(1, 1000+1):
    s = 0
    for j in range(1, math.sqrt(j)):
        if j % i == 0:
            s += j
            if j != i/j:
                s += i/j
    if s == i:
        print(i)