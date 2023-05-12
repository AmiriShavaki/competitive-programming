t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(1)
    elif n == 2:
        if a[0] == a[1]:
            print(1)
        else:
            print(2)
    else:
        ans = n
        l = a[0]; mid = a[1]
        for i in range(2, n):
            if l <= mid <= a[i] or l >= mid >= a[i]:
                mid = a[i]
                ans -= 1
            else:
                l = mid
                mid = a[i]
        print(ans - (l == mid))