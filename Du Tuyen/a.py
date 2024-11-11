import sys

def project_selection(init_cap):
    J = len(cr)
    dp = {0: init_cap}
    
    for group in cr:
        new_dp = {}
        for (current_capital, max_capital) in dp.items():
            for cost, revenue in group:
                if cost > current_capital and cost <= max_capital:
                    new_capital = max_capital + (revenue - cost)
                    if cost not in new_dp or new_capital > new_dp[cost]:
                        new_dp[cost] = new_capital
        if not new_dp:
            return "impossible"
        dp = new_dp
    
    return max(dp.values())

a = [int(s) for s in sys.stdin.readline().split()]
cr = []
for _ in range(a[0]):
    cr.append([[int(t) for t in s.split(':')] for s in sys.stdin.readline().split()])
init_cap = [int(s) for s in sys.stdin.readline().split()]

for i in range(a[1]):
    print(project_selection(init_cap[i]))

#The time complexity of the code is 𝑂(J×nj^2), where J is the number of groups and nj is the number of projects per group, because for each group, we update the DP state for all possible capital values, iterating over all projects in that group.