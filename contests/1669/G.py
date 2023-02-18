def proc_stone(row, col, n):
    global grid
    while row+1 < n and grid[row+1][col] == '.':
        grid[row+1][col] = '*'
        grid[row][col] = '.'
        row += 1

def proc_col(ind, n):
    global grid
    for i in range(n - 1, -1, -1):
        if grid[i][ind] == '*':
            proc_stone(i, ind, n)

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    grid = [list(input()) for _ in range(n)]
    for i in range(m):
        proc_col(i, n)
    for i in range(n):
        print("".join(grid[i]))
