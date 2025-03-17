import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        a = list(map(int, data[idx:idx+n]))
        idx += n
        res = 0
        i = 0
        while i < n-1:
            if a[i] < a[i+1]:
                i += 1
                continue
            res += 1
            j = i
            while j+1 < n and a[j] > a[j+1]:
                j += 1
            i = j
        print(res)

solve()