import math
T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    res = abs(a[0] - 1)
    for i in range(2, n + 1):
        res = math.gcd(res, abs(i - a[i - 1]))
    print(res)