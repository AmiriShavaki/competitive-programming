SQRT = 320
N = 100005
dp = [[0] * SQRT for i in range(N)]

n = int(input())
A = list(map(int, input().split()))

def solve(s, k):
    if k * k > n:
        sum = 0
        for i in range(s, n, k):
            sum += A[i]
        return sum
    else:
        return dp[s][k]

for s in range(n - 1, -1, -1):
    k = 1
    while k * k <= n:
        if s + k < n:
            dp[s][k] = dp[s + k][k] + A[s]
        else:
            dp[s][k] = A[s]
        k += 1

q = int(input())
for i in range(q):
    s, k = map(int, input().split())
    print(solve(s-1, k))