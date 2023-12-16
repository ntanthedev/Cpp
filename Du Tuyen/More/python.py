import math

n = int(input())

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

tonguoc = 0
sl = 0

for i in range(1, n + 1):
    if n % i == 0:
        tonguoc += i 
        if is_prime(i):
            sl += 1

tonguoc -= n 

print("so cac uoc nguyen to khac nhau la: ", sl)
print("tong cac uoc thuc su la: ", tonguoc)