cache = [[-1 for x in range(101)] for y in range(101)]


def comb(n, r):
    if r == 0 or n == r:
        cache[n][r] = 1
        return cache[n][r]
    if cache[n][r] != -1:
        return cache[n][r]
    cache[n][r] = comb(n - 1, r) + comb(n - 1, r - 1)
    return cache[n][r]


n, m = map(int, input().split())
print(comb(n, m))
