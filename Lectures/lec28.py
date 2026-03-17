def min_coins(denominations, amount):
    '''Return the minimum number of coins to make amount'''
    if amount == 0:
        return 0

    min_coins_cached = {}
    for i in range(amount + 1):
        cur_min = float('inf')
        for d in denominations:
            if d <= amount:
                num_coins = 1 + min_coins_cached[amount - d]
                if num_coins < cur_min:
                    cur_min = num_coins
        min_coins_cached[amount] = cur_min
                    
    return min_coins_cached[amount]

def min_coins_rec(denominations, amount, cache = {0:0}):
    '''Return the minimum number of coins to make amount'''
    if amount in cache:
        return cache[amount]

    cur_min = float('inf')
    for d in denominations:
        if d <= amount:
            num_coins = 1 + min_coins_rec(denominations, amount - d, cache)
            if num_coins < cur_min:
                cur_min = num_coins
    cache[amount] = cur_min
    return cur_min

print(min_coins_rec([1, 4, 5, 10], 8))   # 2



def f(L = []):
    L.append(12)
    print(L)

f()
f([])