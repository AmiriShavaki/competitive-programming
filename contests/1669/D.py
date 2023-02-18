def check(s):
    Bseen = False
    Rseen = False
    for ch in s:
        Bseen |= ch == 'B'
        Rseen |= ch == 'R'
    return len(s) == 0 or len(s) > 1 and Bseen and Rseen

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    toked = s.split('W')
    flg = True
    for token in toked:
        flg &= check(token)
    print("YES" if flg else "NO")
