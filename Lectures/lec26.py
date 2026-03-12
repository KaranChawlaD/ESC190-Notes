def fib(n, mem = {}):
    if n in mem:
        return mem[n]
    mem[n] = fib(n-1, mem) + fib(n-2, mem)
    return mem[n]

# Dynamic Programming Approach
def fib_iter(n):
    fib_list = [0] * (n+1)
    fib_list[0:2] = [0, 1]
    for i in range(2, n+1):
        fib_list[i] = fib_list[i-1] + fib_list[i-2]

N = 6

houses = [[7, 6, 7, 8, 9, 20],     # cost of painting each house red
          [3, 8, 9, 22, 12, 8],     # green
          [16, 10, 4, 2, 5, 7]]     # blue

cost = [[0] * N,
        [0] * N,
        [0] * N]

# Base case: first house
cost[0][0] = houses[0][0]    # R(1)
cost[1][0] = houses[1][0]    # G(1)
cost[2][0] = houses[2][0]    # B(1)

# Fill in the rest
for i in range(1, N):
    cost[0][i] = houses[0][i] + min(cost[1][i-1], cost[2][i-1])   # R(i)
    cost[1][i] = houses[1][i] + min(cost[0][i-1], cost[2][i-1])   # G(i)
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[1][i-1])   # B(i)

print(min(cost[0][N-1], cost[1][N-1], cost[2][N-1]))   # 34

cols = [0] * N

# Which color for the last house?
if cost[0][N-1] <= min(cost[1][N-1], cost[2][N-1]):
    cols[N-1] = 0
elif cost[1][N-1] <= min(cost[0][N-1], cost[2][N-1]):
    cols[N-1] = 1
else:
    cols[N-1] = 2

# Backtrack
for i in range(N-2, -1, -1):
    cur_min = float('inf')
    cur_min_col = -1
    for col in [0, 1, 2]:
        if col == cols[i+1]:      # can't be same as next house
            continue
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            cur_min_col = col
    cols[i] = cur_min_col