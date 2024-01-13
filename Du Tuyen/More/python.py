import math

res = 0

n = int(input("n = "))

for i in range(1, n+1):
    res += 1/(i*(i+1)/2)

print("tổng của dãy trên là: ", res)