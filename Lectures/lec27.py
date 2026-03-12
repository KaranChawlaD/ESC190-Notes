houses = [[7, 6, 7, 8, 9, 20],     # cost of painting each house red
          [3, 8, 9, 22, 12, 8],     # green
          [16, 10, 4, 2, 5, 7]]     # blue

N = len(houses[0])

cost = [[0] * N, [0] * N, [0] * N]

cost[0][0], cost[1][0], cost[2][0] = houses[0][0], houses[1][0], houses[2][0]

for i in range(1, N):
    cost[0][i] = houses[0][i] + min(cost[1][i-1], cost[2][i-1])
    cost[1][i] = houses[1][i] + min(cost[0][i-1], cost[2][i-1])
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[1][i-1])

min_cost = min(cost[0][N-1], cost[1][N-1], cost[2][N-1])

colouring = [None] * N

if cost[0][N-1] <= min(cost[0][N-1], cost[1][N-1], cost[2][N-1]):
    colouring[N-1] = 0
if cost[1][N-1] <= min(cost[0][N-1], cost[1][N-1], cost[2][N-1]):
    colouring[N-1] = 1
if cost[2][N-1] <= min(cost[0][N-1], cost[1][N-1], cost[2][N-1]):
    colouring[N-1] = 2

for i in range(N-2, -1, -1):
    cur_min = float('inf')
    for col in [0, 1, 2]:
        if col == colouring[i+1]:
            continue
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            colouring[i] = col

print(colouring)


# coins = [1, 4, 5]
# OPT(i): the leat amount of coins you can use to make amount i

# OPT(i) = 1 + OPT(i-1)
# OPT(i) = 1 + OPT(i-4)
# OPT(i) = 1 + OPT(i-5)

# or OPT(i) = 1 + min(OPT(i-1), OPT(i-4), OPT(i-5))

N = 17
OPT = [float('inf')] * (N+1)

OPT[0] = 0

for i in range(1, N+1):
    for d in [1, 4, 5]:
        if d <= i and 1 + OPT[i-d] < OPT[i]:
            OPT[i] = 1 + OPT[i-d]

print(OPT[8]) # 2, not 3
print(OPT[17]) # 4

# to recover the coins, check after subtracting denomination which OPT is 1 less

coin_soln = []

cur_sum = 17
cur_coins_left = OPT[17]

while (cur_coins_left):
    for d in [1, 4, 5]:
        if (OPT[cur_sum-d] == cur_coins_left-1):
            cur_sum -= d
            cur_coins_left -= 1
            coin_soln.append(d)
            break

print(coin_soln)