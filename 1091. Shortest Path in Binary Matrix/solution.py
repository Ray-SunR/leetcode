class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # use bfs
        if grid[0][0] != 0:
            return -1
        q = [(0, 0, 1)]
        grid[0][0] = -1
        while len(q):
            coord = q.pop(0)
            x = coord[0]
            y = coord[1]
            length = coord[2]
            # print(x)
            # print(y)
            # print('---')
            if x == len(grid) - 1 and y == len(grid[x]) - 1:
                return length
            # bottom-right
            if x + 1 < len(grid) and y + 1 < len(grid[x]) and grid[x + 1][y + 1] == 0:
                q.append((x + 1, y + 1, length + 1))
                grid[x + 1][y + 1] = -1
            # bottom
            if x + 1 < len(grid) and grid[x + 1][y] == 0:
                q.append((x + 1, y, length + 1))
                grid[x + 1][y] = -1
            # right
            if y + 1 < len(grid[x]) and grid[x][y + 1] == 0:
                q.append((x, y + 1, length + 1))
                grid[x][y + 1] = -1
            # bottom-left
            if x + 1 < len(grid) and y - 1 >= 0 and grid[x + 1][y - 1] == 0:
                q.append((x + 1, y - 1, length + 1))
                grid[x + 1][y - 1] = -1
            # top-right
            if x - 1 >= 0 and y + 1 < len(grid[x]) and grid[x - 1][y + 1] == 0:
                q.append((x - 1, y + 1, length + 1))
                grid[x - 1][y + 1] = -1
            # left
            if y - 1 >= 0 and grid[x][y - 1] == 0:
                q.append((x, y - 1, length + 1))
                grid[x][y - 1] = -1
            # top
            if x - 1 >= 0 and grid[x - 1][y] == 0:
                q.append((x - 1, y, length + 1))
                grid[x - 1][y] = -1
            # top-left
            if x - 1 >= 0 and y - 1 >= 0 and grid[x - 1][y - 1] == 0:
                q.append((x - 1, y - 1, length + 1))
                grid[x - 1][y - 1] = -1
        return -1
        
                
