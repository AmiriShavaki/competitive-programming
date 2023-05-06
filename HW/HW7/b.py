n, m = map(int, input().split())
adj_mat = [['0'] * n for i in range(n)]

for i in range(m):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    adj_mat[u][v] = adj_mat[v][u] = '1'

for line in adj_mat:
    print(''.join(line))