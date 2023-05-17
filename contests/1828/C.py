MOD = 1000000007
for T in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()

    bigger_cnt = [0] * len(b)
    j = len(b) - 1
    for i in range(len(b)-1, -1, -1):
        # print(i, j)
        while j >= 0 and a[j] > b[i]:
            j -= 1
        bigger_cnt[i] = len(b) - j - 1
    
    ans = 1
    j = 0
    for i in range(len(b)-1, -1, -1):
        ans = (ans * (bigger_cnt[i] - j)) % MOD
        j += 1
    print(int(ans))