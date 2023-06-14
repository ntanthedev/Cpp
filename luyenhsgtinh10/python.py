def is_prime(n):
    if n < 2:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

n = int(input())
arr = [ ]
for i in range(n):
    arr.append(int(input()))
count = 0
for i in arr:
    if is_prime(i):
        count += 1

print("Số lượng số nguyên tố trong dãy là:", count)
