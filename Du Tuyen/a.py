import math
with open("bai1.INP","r") as r:
    n, k = int(r.readline().split())

ans = -1
if n > 1:
    for i in range(2, math.sqrt(n) + 1):
        if n % i == 0:
            ans = n // i
            break

with open("bai1.OUT","w") as w:
    w.write(int(ans))