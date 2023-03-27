n = input()
ones = n.count('1')
zeros = n.count('0')
print(len(n) - abs(ones - zeros))
