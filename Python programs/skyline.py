grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]

max_row = [max(row) for row in grid]
max_col = [max(col) for col in zip(*grid)]
result = 0
for i, row in enumerate(grid):
    for j, h in enumerate(row):
        result += min(max_row[i], max_col[j]) - h
        #return result
        print(max_col[j])
