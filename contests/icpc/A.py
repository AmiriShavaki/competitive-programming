a, b = input().split()

for i in range(len(a)):
    if a[i] in b:
        first_common_a_ind = i
        first_common_b_ind = b.index(a[i])
        break

ans = [['.'] * len(a) for i in range(len(b))]

ans[first_common_b_ind] = list(a)

for i in range(len(b)):
    ans[i][first_common_a_ind] = b[i]
    print(''.join(ans[i]))
