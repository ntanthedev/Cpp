def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    def calculate_f(arr):
        ops = 0
        while arr:
            ops += 1
            min_val = min(arr)
            l, r = 0, len(arr) - 1
            min_indices = [i for i, x in enumerate(arr) if x == min_val]

            if not min_indices:
                break

            start = min_indices[0]
            end = min_indices[-1]

            new_arr = []
            for i in range(len(arr)):
                if not (start <= i <= end and arr[i] == min_val):
                    new_arr.append(arr[i])
            arr = new_arr
        return ops

    def check(m, initial_a, k_val):
        from collections import Counter
        counts = Counter(initial_a)
        sorted_counts = sorted(counts.values(), reverse=True)

        if m > len(sorted_counts):
            return False

        top_m_counts_sum = sum(sorted_counts[:m])
        changes_needed = n - top_m_counts_sum
        return changes_needed <= k_val

    low = 1
    high = n
    ans = n

    while low <= high:
        mid = (low + high) // 2
        possible = False

        from itertools import combinations
        distinct_vals = sorted(list(set(a)))
        num_distinct = len(distinct_vals)

        if mid <= num_distinct:
            from collections import Counter
            counts = Counter(a)
            sorted_counts = sorted(counts.values(), reverse=True)

            if mid <= len(sorted_counts):
                top_mid_counts_sum = sum(sorted_counts[:mid])
                changes_needed = n - top_mid_counts_sum
                if changes_needed <= k:
                    possible = True

        if possible:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    print(ans)

t = int(input())
for _ in range(t):
    solve()